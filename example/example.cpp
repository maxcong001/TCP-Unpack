#include <iostream>
#include <string>
#include "ringbuffer.hpp"

using namespace std;
int main()
{
    ring_buffer test;
    cout << "test.size in the initial phace is : " << test.size() << " . Now header_p is " << (void *)test.peek_head_p() << endl;
    string tmp_string("Maxx abc");
    test.add(tmp_string.size(), tmp_string.c_str());
    cout << "add " << tmp_string.size() << "elements" << endl;
    cout << "test.size is : " << test.size() << " . Now header_p is " << (void *)test.peek_head_p() << endl;

    char tmp_buff[RB_ELEMENT_SIZE];
    test.get(5, tmp_buff);
    cout << "get first 5 element: " << string(tmp_buff, 5) << endl;
	cout<< "buffer.size is : "<<test.size()<<endl;
    test.get(2, tmp_buff);
    cout << "then get 2 element : " << string(tmp_buff, 2) << endl;
	cout<< "buffer.size is : "<<test.size()<<endl;
    cout << " get 2 elemet return "<<test.get(2, tmp_buff) << endl;
    //cout << "then get 2 element : " << string(tmp_buff, 2) << endl;
	cout<< "buffer.size is : "<<test.size()<<endl;

    char a[RB_ELEMENT_SIZE];

    for (int i = 0; i < RB_SIZE ; i++)
    {
		test.add(RB_ELEMENT_SIZE, a);
		cout<< " in the loop buffer.size is : "<<test.size()<<endl;
    }

    test.get(RB_ELEMENT_SIZE, tmp_buff);
	cout<< "buffer.size is : "<<test.size()<<endl;
    //cout << "get 5 element: " << string(tmp_buff, RB_ELEMENT_SIZE) << endl;
    cout<< "add return "<<test.add(RB_ELEMENT_SIZE, a)<<endl;
	cout<< "buffer.size is : "<<test.size()<<endl;
    cout<< "add return "<<test.add(RB_ELEMENT_SIZE, a)<<endl;
	cout<< "buffer.size is : "<<test.size()<<endl;
    printf("hello world!");
}
