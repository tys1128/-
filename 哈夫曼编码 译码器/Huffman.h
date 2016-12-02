#pragma once
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
#include<iostream>
using namespace std;


struct HfNode {
	char ch = '\0';
	int weight = 0;
	HfNode* left;
	HfNode* right;
	string code;
	bool isLeaf() {
		if (left == NULL&&right == NULL)
			return true;
		return
			false;
	}
	bool operator<(const HfNode& t)const {
		return weight < t.weight;

	}
};
class Huffman {
	HfNode* root;
	int sum;//字符总数
	void Huffman::makeCode(HfNode * t, string c, ofstream& ofile);
	HfNode* getHuffmanTree(string path);//返回哈夫曼树的根节点
public:
	void encode(string path);
	void decode(string path);

};

