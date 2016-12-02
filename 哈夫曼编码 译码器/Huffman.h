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
	vector<HfNode*> hfvec;
	HfNode* root;
	int sum;//�ַ�����

	void Huffman::makeCode(HfNode * t, string c, ofstream& ofile);
	void makeHuffmanTree(string path);//���ع��������ĸ��ڵ�
public:
	Huffman() {
		hfvec.resize(128);
	}
	void encode(string path);
	void decode(string path);

};

