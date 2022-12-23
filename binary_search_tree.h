#pragma once
#include <utility>
#include <iostream>

template <typename Comparable>
class BinarySearchTree {
public:
    class Node{
    public:
        Comparable value{};
        Node* left= nullptr;
        Node* right= nullptr;
    };
    BinarySearchTree() = default;

    ~BinarySearchTree()=default;
    BinarySearchTree(const BinarySearchTree& copy)=default;

// Printmapgen does tree traversal recursively
    void printMapGen(Node* node, int gap, std::ostream& h)
    {
        //though we've built this list iteratively,
        //a recursive solution to printing is a lot better.
        if (node == nullptr)
            //base of recursion
            return;

        gap = gap + i;


        printMapGen(node->right, gap, h);


        for (int n = i; n < gap; n++){
            h << " ";
        }
        h << node->value;
        endl(h);
        //prints the value

        printMapGen(node->left, gap, h);
    }

    void maxRight(Node* trav){
        if (trav->left == nullptr &&trav->right== nullptr){
            return;
        }
        else{
            maxRight(trav->right);
            right_iter++;
        }
    }
    void maxLeft(Node* trav){
        if (trav->left == nullptr &&trav->right== nullptr){
            return;
        }
        else{
            maxLeft(trav->left);
            left_iter++;
        }
    }

    void max_recursive(){
        if(isRoot){
            std::cout<<"max height ="<<0;
            return;
        }
        right_iter=0;
        left_iter=0;
        maxRight(root);

        std::cout<<"max height ="<<std::max(left_iter,right_iter)+1;
    }


    void print_tree(std::ostream& j=std::cout)
    {
        if(isRoot){
            j<<"<empty>\n";
            return;

        }
        else {
            //begin recursion
            printMapGen(root, 0,j);
        }
    }

    void insert(const Comparable& val){
        //while deriving this algorithm, I ran into a problem——there is no
        // way to know what the parent element is once we get to the nullptr.
        // This is simply resolved by adding a temporary parent pointer.
        //tThe issue that follows after this is knowing if the child
        //is right or left of the parent. A simple bool fix.

        bool parity;

        //parity: 0 = left, 1 = right

        if (isRoot){
            root = new Node();
            root->value = val;
            isRoot= false;
            size++;
            return;
        }
        else{
            //send to left
            Node* dig = root;
            //***
            Node* tempP;
            //temporary parent
            while(dig!= nullptr){
                if (val == dig->value){
                    std::cout<<"this value is already in the tree";
                    return;
                }
                if (val > dig->value){
                    //send to the right
                    tempP=dig;
                    dig=dig->right;
                    parity=true;
                }
                else if(val < dig->value){
                    tempP=dig;
                    dig=dig->left;
                    parity=false;
                }
            }
            if (parity==0){
                tempP->left=new Node();
                tempP->left->value=val;
            }
            if (parity==1){
                tempP->right=new Node();
                tempP->right->value=val;
            }

        }
        size++;
    }


    std::pair<Node*,std::pair<Node*,int>> find(const Comparable& val){
        std::pair<Node*,std::pair<Node*,int>> tuple;
        //current,parent,parity

        int parity=-1;

        //parity: 0 = left, 1 = right

        //if (isRoot== true){
            //never touched
        //}
        //else{
            //send to left
            Node* dig = root;
            //***
            Node* tempP;
            //temporary parent
            while(dig!= nullptr){
                if (val == dig->value){
                    tuple.first=dig;
                    tuple.second.first=tempP;
                    tuple.second.second=parity;
                    return tuple;
                }
                if (val > dig->value){
                    //send to the right
                    tempP=dig;
                    dig=dig->right;
                    parity=1;
                }
                else if(val < dig->value){
                    tempP=dig;
                    dig=dig->left;
                    parity=0;
                }
            }
            tuple.first= nullptr;
            tuple.second.first= nullptr;
            tuple.second.second=-1;
            return tuple;
        //}
    }
    void remove(const Comparable& val){
        if(contains(val)== false){
            std::cout<<"not in the tree";
            return;
        }
        if((root->right== nullptr&&root->left== nullptr) &&root->value==val){
            delete root;
            isRoot= true;
            size--;
            return;
        }

        Node* current =(find(val).first);
        Node* parent =(find(val).second.first);
        bool parentParity= find(val).second.second;


        if(current->left == nullptr&&current->right == nullptr){
            //the case where both are nullptr (leaves)
            delete current;
            if(parentParity == 0){
                parent->left= nullptr;
            }
            if(parentParity == 1){
                parent->right= nullptr;
            }
            size--;
            return;
        }
        if(current->left == nullptr&&current->right != nullptr){
            //1/2 cases that one is null and the other has a value (rightval)
            if(parentParity == 0){
                parent->left= current->right;
            }
            if(parentParity == 1){
                parent->right= current->right;
            }
            delete current;
            size--;
            return;
        }
        if(current->left != nullptr&&current->right == nullptr){
            //1/2 cases that one is null and the other has a value (leftval)
            if(parentParity == 0){
                parent->left= current->left;
            }
            if(parentParity == 1){
                parent->right= current->left;
            }
            delete current;
            size--;
            return;
        }
        else{
            //case of both children non-null
            Node* minRST = current->right;
            //Does the good old minimum right subtree dive
            //it also removes the value that has
            Comparable temp;
            while(minRST->left!= nullptr){
                minRST=minRST->left;
            }
            temp = minRST->value;
            remove(minRST->value);
            current->value=temp;
            size--;
        }
        std::cout<<"invalid";

    }

    bool contains(const Comparable& val){
        //while deriving this algorithm, I ran into a problem——there is no
        // way to know what the parent element is once we get to the nullptr.
        // This is simply resolved by adding a temporary parent pointer.
        //tThe issue that follows after this is knowing if the child
        //is right or left of the parent. A simple bool fix.

        //parity: 0 = left, 1 = right

        if (isRoot){
            //TODO:
            return false;
        }
        else{
            Node* dig = root;
            while(dig!= nullptr){
                if (val == dig->value){
                    std::cout<<"this value is already in the tree";
                    return true;
                }
                if (val > dig->value){
                    //send to the right
                    dig=dig->right;
                }
                else if(val < dig->value){
                    dig=dig->left;
                }
            }
            std::cout<<"this value is not in the tree";
            return false;
        }
    }
    const Comparable& find_min() const{
        if(isRoot || size == 0||root== nullptr){
            throw std::out_of_range("the tree is empty");
        }
        else{
            Node* trav = root;
            while(trav->left!= nullptr){
                trav=trav->left;
            }
            return trav->value;
        }

    }
    const Comparable& find_max() const{
        if(isRoot||size==0||root== nullptr){
            throw std::out_of_range("the tree is empty");
        }
        else{
            Node* trav = root;
            while(trav->right!= nullptr){
                trav=trav->right;
            }
            return trav->value;
        }

    }

    [[nodiscard]] int siz() const{
        return size;
    }

private:
    Node* root= nullptr;
    bool isRoot=true;
    int i = 2;
    int size=1;
    int right_iter=0;
    int left_iter=0;

};
