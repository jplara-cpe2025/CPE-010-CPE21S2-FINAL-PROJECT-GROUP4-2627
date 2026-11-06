#ifndef STUDENT_QUEUE_H
#define STUDENT_QUEUE_H

#include <iostream>
#include <string>

struct StudentRequest{
    std::string studentName;
    std::string studentID;
    std::string requestType;
    StudentRequest* next;
};

class StudentQueue{
private:
    StudentRequest* front = nullptr;
    StudentRequest* rear = nullptr;
    int count = 0;

public:
    StudentQueue() = default;

    ~StudentQueue(){
        while (!isEmpty()){ 
            dequeue(); 
        }
    }

    bool isEmpty() const {
            return front == nullptr;
    }

    void enqueue(std::string name, std::string id, std::string request){
        StudentRequest* newNode = new StudentRequest{name, id, request, nullptr};
        if (isEmpty()){
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
        std::cout << "\n" << name << " (ID: " << id << ") added to the waiting queue.\n";
    }

    void dequeue(){
        if (isEmpty()){
            std::cout << "No pending requests in the queue.\n";
            return;
        }
        StudentRequest* temp = front;
        front = front->next;
        if (front == nullptr){
            rear = nullptr; 
        }

        std::cout << "\nProcessing locker assignment for: " << temp->studentName  << " (ID: " << temp->studentID << ")\n";
        delete temp;
        count--;
    }

    // Input and Enqueue
    void requestLockerFromInput(){
        std::string name, id;
        std::cout << "\n=== Request a Locker ===\n";
        std::cout << "Enter Student Name: ";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cout << "Enter Student ID: ";
        std::cin >> id;

        enqueue(name, id, "Locker Request");
    }

    void displayQueue() const {
        if (isEmpty()){
            std::cout << "\nQueue is currently empty.\n";
            return;
        }

        StudentRequest* current = front;
        int pos = 1;
        std::cout << "\n--- Locker Request Waiting Line (" << count << " Waiting) ---\n";
        while (current != nullptr){
            std::cout << pos << ". " << current->studentName << " | ID: " << current->studentID << "\n";
            current = current->next;
            pos++;
        }
        std::cout << "-----------------------------------------------------\n";
    }
};
#endif