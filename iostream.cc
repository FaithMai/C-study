// C++的输入输出流
// cout是ostream的子类ostream_withassign实例对象，关联了标准输出设备
// cin是istream的子类istream_withassign实例对象，关联了标准输出设备
// 
// cerr流对象是标准出错流。cerr流已被指定为与显示器关联。cerr与标准输出流cout的作用和用法差不多。但有一点不同：cout流通常是传送到显示器输出，但也可以被重定向输出到磁盘文件，而cerr流中的信息只能在显示器输出。当调试程序时，往往不希望程序运行时的出错信息被送到其他文件，而要求在显示器上及时输出，这时应该用cerr。cerr流中的信息是用户根据需要指定的。
// clog流对象也是标准出错流，它是console log的缩写。它的作用和cerr相同，都是在终端显示器上显示出错信息。它们之间只有一个微小的区别：ccrr是不经过缓冲区，直接向显示器上输出有关信息，而clog中的信息存放在缓冲区中，缓冲区满后或遇endl时向显示器输出。
// 
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	// 格式输出
	// 方法一：用控制符控制输出格式，需要包含iomanip头文件
	int a;
	cout << "input a:";
	cin >> a;
	cout << "dec:" << dec << a << endl;  // 以十进制形式输出整数，用格式符dec
	cout << "hex:" << hex << a << endl;   // 以十六进制形式输出整数a，用格式符hex
	cout << "oct:" << setbase(8) << a << endl;  // 以八进制形式输出整数a，用格式符setbase(n)，n只能为8,10,16.其他数字默认为10进制
	char *pt = "China";           // pt指向字符串”China”
	cout << setw(10) << pt << endl;  // 指定域宽为10，输出字符串，setw()格式符
	cout << setfill('*') << setw(10) << pt << endl;  // 指定域宽10，输出字符串，空白处以“*”填充
	double pi = 22.0 / 7.0;   // 计算pi值
	cout << setiosflags(ios::scientific) << setprecision(8);  // 按指数形式输出，8位小数。不写默认为6位
	cout << "pi=" << pi << endl;   // 输出pi值
	cout << "pi=" << setprecision(4) << pi << endl;  // 改为4位小数
	cout << "pi=" << setiosflags(ios::fixed) << pi << endl;  // 改为小数形式输出
	cout << "方法二" << endl;
	// 方法二：用流对象成员函数控制输出格式(同时使用两种方法会导致混乱)
	//int a = 21;
	//cout.setf(ios::showbase);//设置输出时的基数符号
	//cout << "dec:" << a << endl; //默认以十进制形式输出a
	//cout.unsetf(ios::dec); //终止十进制的格式设置
	//cout.setf(ios::hex); //设置以十六进制输出的状态
	//cout << "hex:" << a << endl; //以十六进制形式输出a
	//cout.unsetf(ios::hex); //终止十六进制的格式设置
	//cout.setf(ios::oct); //设置以八进制输出的状态
	//cout << "oct:" << a << endl; //以八进制形式输出a
	//cout.unsetf(ios::oct); //终止以八进制的输出格式设置
	//char *pt = "China"; //pt指向字符串"China"
	//cout.width(10); //指定域宽为10
	//cout << pt << endl; //输出字符串
	//cout.width(10); //指定域宽为10
	//cout.fill('*'); //指定空白处以'*'填充
	//cout << pt << endl; //输出字符串
	//double pi = 22.0 / 7.0; //计算pi值
	//cout.setf(ios::scientific);//指定用科学记数法输出
	//cout << "pi="; //输出"pi="
	//cout.width(14); //指定域宽为14
	//cout << pi << endl; //输出pi值
	//cout.unsetf(ios::scientific); //终止科学记数法状态
	//cout.setf(ios::fixed); //指定用定点形式输出
	//cout.width(12); //指定域宽为12
	//cout.setf(ios::showpos); //在输出正数时显示“+”号
	//cout.setf(ios::internal); //数符出现在左侧
	//cout.precision(6); //保留6位小数
	//cout << pi << endl; //输出pi，注意数符“+”的位置
// 1、成员函数width(n)和控制符setw(n)只对其后的第一个输出项有效。如果要求在输出数据时都按指定的同一域宽n输出，不能只调用一次width(n)，而必须在输出每一项前都调用一次width(n)。
// 2、在表5中的输出格式状态分为5组，每一组中同时只能选用一种(例如，dec，hex和oct中只能选一，它们是互相排斥的)，在用成员函数setf和控制符setiosflags设置输出格式状态后，如果想改设置为同组的另一状态，应当调用成员函数unsetf(对应于成员函数setf)或resetiosflags(对应于控制符setiosflags)，先终止原来设置的状态。然后再设置其他状态。
//    同理，程序倒数第8行的unsetf函数的调用也是不可缺少的。读者不妨上机试一试。
// 3、用setf函数设置格式状态时，可以包含两个或多个格式标志，由于这些格式标志在ios类中被定义为枚举值，每一个格式标志以一个二进位代表，因此可以用“位或”运算符“|”组合多个格式标志。
// 4、可以看到：对输出格式的控制，既可以用控制符，也可以用cout流的有关成员函数，二者的作用是相同的。控制符是在头文件iomanip中定义的，因此用控制符时，必须包含iomanip头文件。cout流的成员函数是在头文件iostream中定义的，因此只需包含头文件iostream，不必包含iomanip。许多程序人员感到使用控制符方便简单，可以在一个cout输出语句中连续使用多种控制符。

	// 用流成员函数put输出字符
	cout.put(71).put(79).put(79).put(68).put('\n');  // 可以一次输出多个字符
	
	// 输入
	// cin流,只有在正常状态时，才能从输入流中提取数据，当遇到无效字符或遇到文件结束符，输人流cin就处于出错状态。cin正常状态时,返回一个非0值。出错状态，返回0值。
	// 用字符输入的流函数
	// 注意：就算只有cin语句，也会停下来进行输入eg:  cin;
	// cin.get()  // 从指定输入流中读取一个字符，一般用c = cin.get() 将读取的字符赋值给c
	// cin.get(ch) // 从指定的输入流中读取一个字符,并且赋值给ch
	// cin.get(字符数组,字符个数n,终止字符) //  其作用是从输入流中读取n-1个字符，赋给指定的字符数组(或字符指针指向的数组)，如果在读取n-1个字符之前遇到指定的终止字符，则提前结束读取。如果读取成功则函数返回非0值(真)，如失败(遇文件结束符)则函数返回0值(假)
	// cin.getline(字符数组(或字符指针)，字符个数n，终止标志字符) 与cin.get(字符数组,字符个数n,终止字符)用法相似
	// 区别：用getline函数从输入流读字符时，遇到终止标志字符时结束，指针移到该终止标志字符之后，下一个getline函数将从该终止标志的下一个字符开始接着读入。如本程序运行结果所示那样。如果用cin．get函数从输入流读字符时，遇终止标志字符时停止读取，指针不向后移动，仍然停留在原位置。下一次读取时仍从该终止标志字符开始。这是getline函数和get函数不同之处。eg:若是换行符很容易看出区别

	// istream类的其他成员函数
	// eof函数 cin.eof() 表示“文件结束”。从输入流读取数据，如果到达文件末尾(遇文件结束符)，eof函数值为非零值(表示真)，否则为0(假)
	// peek函数 c=cin.peek();  peek函数的作用是观测下一个字符(一般读取完就会往后移动),cin.peek函数的返回值是指针指向的当前字符，但它只是观测，指针仍停留在当前位置，并不后移。如果要访问的字符是文件结束符，则函数值是EOF(-1)。
	// putback函数 cin．putback(ch);  其作用是将前面用get或getline函数从输入流中读取的字符ch返回到输入流，插入到当前指针位置，以供后面读取
	// ignore函数  cin.ignore(n，终止字符) 函数作用是跳过输入流中n个字符，或在遇到指定的终止字符时提前结束(此时跳过包括终止字符在内的若干字符) 也可以不带参数或只带一个参数。如ignore()(n默认值为1，终止字符默认为EOF)

	return 0;
}

