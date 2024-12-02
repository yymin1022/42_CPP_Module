#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(int argc, char **argv){
    for(int i = 1; i < argc; i++){
        int j = 0;
        while(argv[i][j]){
            if(!isdigit(argv[i][j++])){
                throw PmergeException();
            }
        }

        int num;
        std::stringstream ss(argv[i]);
        ss >> num;
        if(ss.fail() || num < 1){
            throw PmergeException();
        }

        dataVector.push_back(std::vector<int>(1, num));
        dataList.push_back(std::list<int>(1, num));
    }
}

PmergeMe::PmergeMe(const PmergeMe &copy)
	: dataList(copy.dataList), dataVector(copy.dataVector){}

PmergeMe::~PmergeMe(){}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy){
    if(this != &copy){
        dataVector = copy.dataVector;
        dataList = copy.dataList;
    }
    return *this;
}

int PmergeMe::getElementSize(){
	return (dataVector.size());
}

int PmergeMe::getSizeList(){
    int lstSize = 0;
    int elementSize =(*getIterL(0)).size();

    for(int i = 0; i < static_cast<int>(dataList.size()); i++){
        if(static_cast<int>((*getIterL(i)).size()) == elementSize){
            lstSize++;
        }
    }

    return lstSize;
}

int PmergeMe::binarySearchList(int val, int left, int right){
    while(left <= right){
        int mid =(left + right) / 2;
        if((*getIterLL(mid, 0)) <= val){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return left;
}

void PmergeMe::insertList(int idx, int insertIdx){
    std::list<int> lInsert;
    for(int i =(*getIterL(idx)).size() / 2; i > 0; i--){
        lInsert.push_back((*getIterL(idx)).back());
       (*getIterL(idx)).pop_back();
    }
    dataList.insert(getIterL(insertIdx), lInsert);
}

void PmergeMe::lastSortList(int idx){
    int insertIdx = binarySearchList((*getIterL(idx)).front(), 0, idx - 1);
    dataList.insert(getIterL(insertIdx),(*getIterL(idx)));
    dataList.erase(getIterL(idx + 1));
}

void PmergeMe::mergeElementList(int idx1, int idx2){
    while(!(*getIterL(idx1)).empty()){
       (*getIterL(idx2)).push_back((*getIterL(idx1)).back());
       (*getIterL(idx1)).pop_back();
    }
    dataList.erase(getIterL(idx1));
}

void PmergeMe::sortList(){
    int lstSize = getSizeList();
    if(lstSize == 1) return;

    int i = 0;
    while(i < lstSize / 2){
        if((*getIterLL(i, 0)) <(*getIterLL(i + 1, 0))){
            mergeElementList(i, i + 1);
        }else{
            mergeElementList(i + 1, i);
        }
        i++;
    }

    sortList();

    int maxIdx = lstSize / 2 - 1;
    int AddNum = 0;
    int k = 1;
    int nextJN, preJN;
    int size =(*getIterL(0)).size();
    do{
        preJN = getJacobsthal(k - 1);
        nextJN = std::min(getJacobsthal(k), maxIdx);
        int gap = nextJN - preJN;
        int idx = nextJN + AddNum;
        for(int i = 0; i < gap; i++){
            if(static_cast<int>((*getIterL(idx)).size()) != size){
                i--;
                idx--;
            }else{
                int insertIdx = binarySearchList((*getIterL(idx)).back(), 0, idx - 1);
                insertList(idx, insertIdx);
                AddNum++;
            }
        }
        k++;
    }while(nextJN != maxIdx);

    if(lstSize & 1){
        lastSortList(lstSize - 1);
    }
}

std::list< std::list<int> >::iterator PmergeMe::getIterL(int idx){
	std::list< std::list<int> >::iterator iter = dataList.begin();
	for(int i = 0; i < idx; i++)
		iter++;
	return (iter);
}

std::list<int>::iterator PmergeMe::getIterLL(int idx1, int idx2){
	std::list<int>::iterator iter = (*getIterL(idx1)).begin();
	for(int i = 0; i < idx2; i++)
		iter++;
	return (iter);
}

std::list<int> PmergeMe::getResultList(){
    std::list<int> retList;
    for(int i = 0; i < static_cast<int>(dataList.size()); i++){
        retList.push_back((*getIterLL(i, 0)));
    }
    return retList;
}

int PmergeMe::binarySearchVector(int val, int left, int right){
    while(left <= right){
        int mid =(left + right) / 2;
        if(dataVector[mid][0] <= val){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return left;
}

int PmergeMe::getJacobsthal(int k){
    if(k == 0) return -1;
    int n =(k % 2) ? -1 : 1;
    return(std::pow(2, k + 1) + n) / 3 - 1;
}

int PmergeMe::getSizeVector(){
    int vecSize = 0;
    int elementSize = dataVector[0].size();

    for(int i = 0; i < static_cast<int>(dataVector.size()); i++){
        if(static_cast<int>(dataVector[i].size()) == elementSize){
            vecSize++;
        }
    }

    return vecSize;
}

void PmergeMe::insertVector(int idx, int insertIdx){
    std::vector<int> vInsert;
    for(int i = dataVector[idx].size() / 2; i > 0; i--){
        vInsert.push_back(dataVector[idx].back());
        dataVector[idx].pop_back();
    }
    dataVector.insert(dataVector.begin() + insertIdx, vInsert);
}

void PmergeMe::lastSortVector(int idx){
    int insertIdx = binarySearchVector(dataVector[idx].front(), 0, idx - 1);
    dataVector.insert(dataVector.begin() + insertIdx, dataVector[idx]);
    dataVector.erase(dataVector.begin() + idx + 1);
}

void PmergeMe::mergeElementVector(int idx1, int idx2){
    while(!dataVector[idx1].empty()){
        dataVector[idx2].push_back(dataVector[idx1].back());
        dataVector[idx1].pop_back();
    }
    dataVector.erase(dataVector.begin() + idx1);
}

void PmergeMe::sortVector(){
    int vecSize = getSizeVector();
    if(vecSize == 1) return;

    int i = 0;
    while(i < vecSize / 2){
        if(dataVector[i][0] < dataVector[i + 1][0]){
            mergeElementVector(i, i + 1);
        }else{
            mergeElementVector(i + 1, i);
        }
        i++;
    }

    sortVector();

    int maxIdx = vecSize / 2 - 1;
    int AddNum = 0;
    int k = 1;
    int nextJN, preJN;
    int size = dataVector[0].size();
    do{
        preJN = getJacobsthal(k - 1);
        nextJN = std::min(getJacobsthal(k), maxIdx);
        int gap = nextJN - preJN;
        int idx = nextJN + AddNum;
        for(int i = 0; i < gap; i++){
            if(static_cast<int>(dataVector[idx].size()) != size){
                i--;
                idx--;
            }else{
                int insertIdx = binarySearchVector(dataVector[idx].back(), 0, idx - 1);
                insertVector(idx, insertIdx);
                AddNum++;
            }
        }
        k++;
    }while(nextJN != maxIdx);

    if(vecSize & 1){
        lastSortVector(vecSize - 1);
    }
}

std::vector<int> PmergeMe::getResultVector(){
    std::vector<int> retVec;
    for(int i = 0; i < static_cast<int>(dataVector.size()); i++){
        retVec.push_back(dataVector[i][0]);
    }
    return retVec;
}

const char *PmergeMe::PmergeException::what() const throw(){
	return ("Error");
}
