//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//void main() {
//	vector<int> v;
//	v.push_back(6);
//	v.push_back(7);
//	v.push_back(4);
//	v.push_back(8);
//
//	vector<int>v2;
//	v2.push_back(12);
//	v2.push_back(34);
//	v2.push_back(23);
//
//	vector<int>r(v.size() + v2.size());
//	copy_n(v.begin(), v.size(), r.begin());
//	copy_n(v2.begin(), v2.size(), r.begin() + v.size());
//
//	for(int i=0;i<r.size();i++){
//		cout << r[i] << " ";
//	}
//
//	reverse(r.begin(), r.begin()+v.size());
//	cout << endl;
//	for (int i = 0; i < r.size(); i++) {
//		cout << r[i] << " ";
//	}
//
//
//	/*vector<int>::iterator it = v.begin();
//	while (it != v.end()) {
//		cout << *it << endl;
//		it++;
//	}
//
//	vector<int> v2(v.size());
//	vector<int>::iterator itEnd = v.begin() + 3;
//
//	copy(v.begin(), v.end() , v2.begin());
//
//	vector<int>::iterator it2 = v2.begin();
//	while (it2 != v2.end()) {
//		cout << *it2 << endl;
//		it2++;
//	}
//
//	vector<int> v3(2);
//	copy(v.begin(), v.begin()+2, v3.begin());
//
//	cout << endl;
//	vector<int>::iterator it3 = v3.begin();
//	while (it3 != v3.end()) {
//		cout << *it3 << endl;
//		it3++;
//	}
//
//	vector<int> v4(2);
//	copy_n(v.begin(), 2, v4.begin());
//
//	cout << endl;
//	vector<int>::iterator it4 = v4.begin();
//	while (it4 != v4.end()) {
//		cout << *it4 << endl;
//		it4++;
//	}*/
//	
//
//}