#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Structure to hold Parcel records
struct Parcel {
    int trackingID;
    string destination;
    float weight;
};

// ---------------------------------------------------------
// 1. BINARY SEARCH (By Tracking ID)
// ---------------------------------------------------------
int binarySearch(vector<Parcel>& parcels, int targetID) {
    int left = 0;
    int right = parcels.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (parcels[mid].trackingID == targetID)
            return mid; 
        if (parcels[mid].trackingID < targetID)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; 
}

// ---------------------------------------------------------
// 2. MERGE SORT (By Parcel Weight Ascending)
// ---------------------------------------------------------
void merge(vector<Parcel>& parcels, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Parcel> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = parcels[left + i];
    for (int j = 0; j < n2; j++) R[j] = parcels[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].weight <= R[j].weight) {
            parcels[k] = L[i];
            i++;
        } else {
            parcels[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) { parcels[k] = L[i]; i++; k++; }
    while (j < n2) { parcels[k] = R[j]; j++; k++; }
}

void mergeSort(vector<Parcel>& parcels, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(parcels, left, mid);
        mergeSort(parcels, mid + 1, right);
        merge(parcels, left, mid, right);w4
    }
}

// ---------------------------------------------------------
// 3. QUICK SORT (By Destination City Alphabetically)
// ---------------------------------------------------------
int partition(vector<Parcel>& parcels, int low, int high) {
    string pivot = parcels[high].destination;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (parcels[j].destination < pivot) {
            i++;
            swap(parcels[i], parcels[j]);
        }
    }
    swap(parcels[i + 1], parcels[high]);
    return (i + 1);
}

void quickSort(vector<Parcel>& parcels, int low, int high) {
    if (low < high) {
        int pi = partition(parcels, low, high);
        quickSort(parcels, low, pi - 1);
        quickSort(parcels, pi + 1, high);
    }
}


int main() {
    // Original Sample Data
    vector<Parcel> originalParcels = {
        {105, "Mumbai", 2.5},
        {102, "Delhi", 1.2},
        {108, "Bangalore", 4.0},
        {101, "Chennai", 0.8},
        {104, "Kolkata", 3.1}
    };

    // Print Original Array using a standard for loop
    cout << "--- Original Parcel Records ---\n";
    cout << "ID\tWeight(kg)\tDestination\n";
    cout << "-------------------------------------------\n";
    for (int i = 0; i < originalParcels.size(); i++) {
        cout << originalParcels[i].trackingID << "\t" 
             << originalParcels[i].weight << "\t\t" 
             << originalParcels[i].destination << "\n";
    }
    cout << "\n";

    // 1. BINARY SEARCH DEMONSTRATION
    vector<Parcel> searchParcels = originalParcels; 
    
    // Simple bubble sort to prep for Binary Search (instead of advanced lambda sort)
    for(int i = 0; i < searchParcels.size() - 1; i++) {
        for(int j = 0; j < searchParcels.size() - i - 1; j++) {
            if(searchParcels[j].trackingID > searchParcels[j+1].trackingID) {
                swap(searchParcels[j], searchParcels[j+1]);
            }
        }
    }
    
    int searchID = 104;
    int index = binarySearch(searchParcels, searchID);
    cout << "--- Binary Search for Tracking ID: " << searchID << " ---\n";
    if (index != -1) {
        cout << "Found! Destination: " << searchParcels[index].destination 
             << ", Weight: " << searchParcels[index].weight << "kg\n\n";
    } else {
        cout << "Tracking ID not found.\n\n";
    }

    // 2. MERGE SORT DEMONSTRATION (By Weight)
    vector<Parcel> mergeSortedParcels = originalParcels;
    mergeSort(mergeSortedParcels, 0, mergeSortedParcels.size() - 1);
    
    cout << "--- Parcels Sorted by Weight (Merge Sort) ---\n";
    cout << "ID\tWeight(kg)\tDestination\n";
    cout << "-------------------------------------------\n";
    for (int i = 0; i < mergeSortedParcels.size(); i++) {
        cout << mergeSortedParcels[i].trackingID << "\t" 
             << mergeSortedParcels[i].weight << "\t\t" 
             << mergeSortedParcels[i].destination << "\n";
    }
    cout << "\n";

    // 3. QUICK SORT DEMONSTRATION (By Destination)
    vector<Parcel> quickSortedParcels = originalParcels;
    quickSort(quickSortedParcels, 0, quickSortedParcels.size() - 1);
    
    cout << "--- Parcels Sorted by Destination (Quick Sort) ---\n";
    cout << "ID\tWeight(kg)\tDestination\n";
    cout << "-------------------------------------------\n";
    for (int i = 0; i < quickSortedParcels.size(); i++) {
        cout << quickSortedParcels[i].trackingID << "\t" 
             << quickSortedParcels[i].weight << "\t\t" 
             << quickSortedParcels[i].destination << "\n";
    }
    cout << "\n";

    return 0;
}