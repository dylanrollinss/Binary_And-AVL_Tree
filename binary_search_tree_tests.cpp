#include <iostream>
#include "binary_search_tree.h"

using std::cout, std::endl;

int main() {
    BinarySearchTree<int> test;

    try{
        test.find_max();
    }
    catch(std::out_of_range&){

    }
    try{
        test.find_min();
    }
    catch(std::out_of_range&){

    }

    try{
        test.max_recursive();
    }
    catch(std::out_of_range&){

    }

    test.insert(9);
    test.insert(8);
    test.insert(10);
    test.insert(100);
    test.remove(10);
    test.remove(100);
    test.remove(8);
    test.insert(8);
    test.insert(3);
    cout<<test.find_min();
    test.insert(7);
    test.insert(12);
    test.insert(15);
    test.insert(10);
    test.remove(9);
    test.print_tree();

    cout <<"size="<<test.siz()<<" ";


    BinarySearchTree<int> tree2;
    tree2.insert(6);
    tree2.insert(6);
    tree2.insert(4);
    tree2.insert(2);
    tree2.insert(8);
    tree2.insert(10);
    tree2.remove(6);
    tree2.insert(100);
    tree2.insert(9);
    tree2.insert(1000);
    tree2.insert(10000);
    cout<<"max="<<tree2.find_max();

    tree2.print_tree();

    cout <<"size="<<tree2.siz();

    BinarySearchTree<int> tree3;

    tree3.insert(2);
    tree3.remove(2);
    tree3.insert(7);
    tree3.insert(6);
    tree2.remove(7);
    tree2.remove(6);



    tree3.print_tree();

    BinarySearchTree<int> mark2 = tree2;

    cout<<"hmm";
    mark2.print_tree();
    tree2.max_recursive();

    BinarySearchTree<int> hmm;
    hmm.max_recursive();
    hmm.insert(1);
    hmm.remove(1);






}
