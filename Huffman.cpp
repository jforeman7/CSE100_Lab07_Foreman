// Jeff Foreman
// CSE 100 03L
// Lab 07: Huffman Codes
// 30 Oct 2017
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class HuffmanCodes
{
 struct Node
 {
  char data;
  size_t freq;
  Node* left;
  Node* right;
  Node(char data, size_t freq) : data(data),
                                 freq(freq),
                                 left(NULL),
                                 right(NULL)
                                 {}
 ~Node()
 {
   delete left;
   delete right;
 }
 };

 struct compare
 {
  bool operator()(Node* l, Node* r)
  {
    return (l->freq > r->freq);
  }
};

Node* top;

void printCode(Node* root, std::string str)
{
  if(root == NULL)
   return;

 if(root->data == '$')
 {
  printCode(root->left, str + "0");
  printCode(root->right, str + "1");
 }

 if(root->data != '$')
 {
   std::cout << root->data << " : " << str << "\n";
   printCode(root->left, str + "0");
   printCode(root->right, str + "1");
 }
}

public:
  HuffmanCodes() {};
  ~HuffmanCodes()
  {
    delete top;
  }
  void GenerateCode(std::vector<char>& data, std::vector<size_t>& freq, size_t size)
  {
   Node* left;
   Node* right;
   std::priority_queue<Node*, std::vector<Node*>, compare > minHeap;

   for(size_t i = 0; i < size; ++i)
   {
      minHeap.push(new Node(data[i], freq[i]));
   }

    while(minHeap.size() != 1)
    {
      left = minHeap.top();
      minHeap.pop();

      right = minHeap.top();
      minHeap.pop();

      top = new Node('$', left->freq + right->freq);
      top->left  = left;
      top->right = right;
      minHeap.push(top);
     }
    printCode(minHeap.top(), "");
 }
};

 int main()
 {
  HuffmanCodes set1;
	 int size;
	 cin >> size;
	 
  std::vector<char> data;
  std::vector<size_t> freq;
	 
	 for (int i = 0; i < size; i++)
	 {
			data[i] = 'a';
		 	cin >> freq[i];
	 }
  set1.GenerateCode(data, freq, size);

  return 0;
}
