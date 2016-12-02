#include<iomanip>
#include<iterator>
#include "Huffman.h"
bool compWeight(const HfNode* a, const HfNode* b) {
	return a->weight < b->weight ? true : false;
}
void Huffman::makeHuffmanTree(string path) {
	const int MAXSIZE = 128;
	ifstream ifile(path);
	vector<HfNode*> hfvec(MAXSIZE);

	for (int i = 0; i < MAXSIZE; i++) {//initialization
		hfvec[i] = new HfNode();
		hfvec[i]->ch = i;
	}

	for (sum = 1;; sum++) {//读入数据
		char ch = ifile.get();
		if (ifile.eof())
			break;
		else {
			hfvec[ch]->weight++;//加权
		}
	}
	for (vector<HfNode*>::iterator i = hfvec.begin(); i != hfvec.end(); ) {
		if ((*i)->weight == 0) {
			i = hfvec.erase(i);
		}
		else
			i++;
	}
	stable_sort(hfvec.begin(), hfvec.end(), compWeight);
	for (int i = 0; i < hfvec.size() - 1; i++) {//组合
		HfNode* t = new HfNode();
		HfNode* p1 = hfvec[i];
		HfNode* p2 = hfvec[i + 1];
		t->weight = p1->weight + p2->weight;
		t->left = p1;
		t->right = p2;

		hfvec[i + 1] = t;//加入后排序
		stable_sort(hfvec.begin() + i + 1, hfvec.end(), compWeight);
	}
	ifile.close();
	root = hfvec.back();
}

void Huffman::encode(string path) {
	ifstream ifile(path);
	ofstream ofile("encode file.txt");
	makeHuffmanTree(path);

	makeCode(root, "", ofile);

}
void Huffman::makeCode(HfNode* t, string c, ofstream& ofile) {
	if (t == NULL)
		return;
	else {
		t->code = c;
		makeCode(t->left, t->code + "0", ofile);
		makeCode(t->right, t->code + "1", ofile);
	}
	if (t->isLeaf()) {
		ofile << t->ch << "\t" << setprecision(2) << t->weight * 100 / (float)sum << "%\t\t" << t->code << endl;
		//ofile.flush();
	}
}
void Huffman::decode(string path) {

}
