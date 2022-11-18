#include "stuck.h"
#include "stack_LSL.h"
#include "deque.h"

int main()
{
	STACK<int> st;
	STACK_knot<int> stl;
	Deque<int> dec(5);
	//cout << "array\n";
	//st.push(5);
	//st.push(7);
	//st.push(11);
	//st.outList();
	//cout << st.size_stack() << "\n";
	//cout << st.retrieve() << "\n";
	//st.pop(); cout << st.retrieve() << "\n";
	//cout << "list\n";
	//stl.push(7);
	//stl.push(6);
	//stl.push(15);
	//stl.outlist();
	//cout << stl.size_knot() << '\n';
	//stl.pop();
	//stl.outlist();
	cout << "dec\n";
	dec.pushHead(22);
	dec.pushTail(12);
	//dec.print();
	cout << dec.popHead() << "\n";
	cout << dec.popHead() << "\n";

	return 0;
}
