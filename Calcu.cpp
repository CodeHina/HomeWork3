#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <cctype>
#include <cstdio>

using namespace std;

int main()
{

	//响应行后的主体数据
    cout << "Content-type:text/html\r\n";

    int n = 0;

    if(getenv("CONTENT_LENGTH"))//获取环境变量
        n = atoi(getenv("CONTENT_LENGTH") );//确定当前内容长度

	//获取当前传递的字符串
	string str = "";
    for (int i = 0; i < n; i++){
        char c;
        cin.get(c);
        str += c;
    }

	//处理字符串
	vector<int> nums;
	bool op[4];
	memset(op, false, 4);
	for(int i = 0; i < n; ++i){
		if('0' <= str[i] <= '9'){
			nums.push_back(str[i] - '0');
		}
		else if(str[i] == '+'){
			op[0] = true;
		}
		else if(str[i] == '-'){
			op[1] = true;
		}
		else if(str[i] == '*'){
			op[2] = true;
		}
		else if(str[i] == '/'){
			op[3] = true;
		}
	}

	int res;
	for(int i = 0; i < 4; ++i){
		if(op[i] == true){
			if(i == 0){
				res = nums[0] + nums[1];
			}
			if(i == 1){
				res = nums[0] - nums[1];
			}
			if(i == 2){
				res = nums[0] * nums[1];
			}
			if(i == 3){
				if(nums[1] == 0){
					cerr << "/0段错误" << endl;
					break;
				}
				res = nums[0] / nums[1];
			}

		}
	}

	//输出结果
	cout << res << endl;


    return 0;

}
