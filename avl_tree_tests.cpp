#include <iostream>
#include "avl_tree.h"
//#include <random>

using std::cout, std::endl;

int main() {


    AVLTree<int> q;

    q.insert(5);
    q.print_tree();
    q.insert(6);

    q.print_tree();

    q.insert(2);
    q.print_tree();
    q.insert(98);
    q.print_tree();
    q.insert(76);
    q.print_tree();
    q.insert(67);
    q.print_tree();





    AVLTree<int> j;
    j.insert(5);
    j.print_tree();
    j.insert(6);
    j.print_tree();
    j.insert(7);
    j.print_tree();
    j.insert(80);
    j.print_tree();
    j.insert(100);


    j.print_tree();

    AVLTree<int> k;
    k.insert(490);
    k.print_tree();

    k.insert(100);

    k.print_tree();

    k.insert(10);

    k.print_tree();
    k.insert(9);

    k.print_tree();
    k.insert(8);

    k.print_tree();



    AVLTree<int> l;
    std::cout<<"l=\n";
    l.insert(5);
    l.insert(6);
    l.insert(3);
    l.insert(4);

    l.insert(10);
    l.insert(11);
    l.print_tree();
    l.insert(12);
    l.print_tree();
    l.insert(13);
    l.print_tree();
    l.insert(14);



    l.print_tree();



    AVLTree<int> z;

    for(int i =0;i<=20;i++){
        if(i==4){

        }
        z.insert(i);
        z.print_tree();
    }

    z.print_tree();

    z.insert(49);

    //std::cout<<" p * * * * * * * * p\n\n";
    AVLTree<int> p;

    p.insert(74);
    //std::cout<<" p * * * * * * * * p\n\n";
    p.print_tree();
    p.insert(91);
    //std::cout<<" p * * * * * * * * p\n\n";
    p.print_tree();
    p.insert(2);
    //std::cout<<" p * * * * * * * * p\n\n";
    p.print_tree();
    p.insert(40);
    //std::cout<<" p * * * * * * * * p\n\n";
    p.print_tree();
    p.insert(97);
    //std::cout<<" p * * * * * * * * p\n\n";
    p.print_tree();
    //std::cout<<" p * * * * * * * * p\n\n";

    p.insert(44);




    p.print_tree();

    //std::cout<<"* * * * * * * *\n\n";
    AVLTree<int> t;

    t.print_tree();






    /*
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(1, 100); // define the range
          */

    int list[30]={12,18,28,75,13,37,55,26,79,53,57,78,21,32,72,38,7,6,55,61,20,51,100,4,8,97,5,63,4,41};


    for(int i=0;i<=29;i++){
        cout<<list[i]<<",";
    }
    for(int i=0;i<=29;i++){;
        t.insert(list[i]);
        t.print_tree();
    }


}
