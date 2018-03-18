#include "Generic.h"

int main() {
	string* pStr, *parole;
	parole = new string[8];
	ArrayList<string> a, z, l, *m;
	string b = parole[0] = "as" ;
	string c = parole[1] = "asas" ;
	string d = parole[2] = "ass" ;
	string e = parole[3] = "asfs" ;
	string f = parole[4] = "aswer" ;
	string g = parole[5] = "assg" ;
	string h = parole[6] = "asate" ;
	string i = parole[7] = "ashey" ;
	string w = "blabla";

	a.add(parole, 8);

	ArrayList<string> *j = a.subList(2, 5);

	z.add(b);
	z.add(c);
	z.add(d);
	z.add(e);
	z.add(f);
	z.add(g);
	z.add(h);
	z.add(i);

	if(a.equals(z))
		cout << "sono uguali" << endl;

	cout << "a: ";
	cout << a.to_string() << endl;
	cout << "a17";
	l.add(a);
	a.removeRange(1,7);
	cout << a.to_string() << endl;
	cout << "j: ";
	cout << j->to_string() << endl;
	cout << "pS " << a.size() << endl;
	pStr = j->toArray();
	cout << "Array = { ";
	for(int i=0; i<j->size()-1; i++)
		cout << pStr[i] << ", ";
	cout << pStr[j->size()-1] << " }" << endl;

	a.add(2, w);
	cout << "a: ";
	cout << a.to_string() << endl;

	m = new ArrayList<string>(a);
	cout << m->to_string() << endl;
	cout << l.to_string() << endl;
	cout << l.leng() << endl;
	cout << "trimmo l" << endl;
	l.trimToSize();
	cout << l.leng() << endl;


	return 0;
}
