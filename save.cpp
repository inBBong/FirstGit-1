#include"save.h"

int main() {

	cout << "2024 STL" << endl;

	save("save.cpp");
}

void save(string_view fileName) {
	//���� ������ ����.
	ifstream in{ fileName.data() }; //<-- ������ ������ Ÿ��
	if (!in) {
		cout << "������ ���� ���߽��ϴ�. " << endl;
		exit(0);
	}
	//�� ������ �����̱� ���� ����.
	ofstream out("2024 1 ��56��78 ���� ����.txt", ios::app);

	//���� ������ ��� ������ �о� �� ���Ͽ� �����δ�. 
	vector<char> v{ istreambuf_iterator<char>{in}, {} };
	copy(v.begin(), v.end(), ostreambuf_iterator<char>{out});

	for (char c : v)
		cout << c;

	//�����ϴ� �ð��� ���Ͽ� ����Ѵ�.
	auto now = chrono::system_clock::now();
	cout << now << endl;

	auto time = chrono::system_clock::to_time_t(now); //utc �ð����� ��ȯ
	auto lt = localtime(&time); //���� �ð����� ��ȯ

	auto old = out.imbue(locale("ko_KR"));
	out << "=============================" << endl;
	out << fileName << put_time(lt, ", ����ð�:  %x %A %X ") << endl;
	out << "=============================" << endl;
	out.imbue(old);

}