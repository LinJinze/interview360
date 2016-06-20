#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define H_ARRAYSIZE(a) \
    ((sizeof(a) / sizeof(*(a))) / \
    static_cast<size_t>(!(sizeof(a) % sizeof(*(a)))))

/*
 *Mountain Infomation
 */
class Mountain
{
private:
	int x;	//mountain.start
	int y;	//mountain.end
	int h;	//mountain.height

public:
	//Mountain initialize
	Mountain()
	{
		x = 0;
		y = 0;
		h = 0;
	}
	//Mountain initialize(args)
	Mountain(int mounX,int mounY,int mounH)
	{
		x = mounX;
		y = mounY;
		h = mounH;
	}
	//Mountain initialize
	int contain(int coordX)
	{
		if(coordX >= x && coordX < y)
		{
			return h;
		}
		else
		{
			return 0;
		}
	}
	//setter and getter
	int getX()
	{
		return x;
	}
	void setX(int mounX)
	{
		x = mounX;
	}
	int getY()
	{
		return y;
	}
	void setY(int mounY)
	{
		y = mounY;
	}
	int getH()
	{
		return h;
	}
	void setH(int mounH)
	{
		h = mounH;
	}
};

/*
 *Count Steps
 */
int resolve(const char* input)
{
	//no data
	if(input == NULL || sizeof(input) == 0)
	{
		return -1;
	}
	//load data
	char* inputs = new char[strlen(input) + 1];
	strcpy(inputs, input);
	int number = atoi(strtok(inputs,"\n"));
	Mountain *mouns = (Mountain *)calloc(number,sizeof(Mountain));
	int no;
	int end = 0;
	for(no = 0; no < number; no++)
	{
		int x = atoi(strtok(NULL,",\n"));
		int y = atoi(strtok(NULL,",\n"));
		int h = atoi(strtok(NULL,",\n"));
		mouns[no] = Mountain(x,y,h);
		if(y > end)
			end = y;
	}
	//count steps
	int coordX = 0;	//position now
	int Height = 0;	//height now
	int nextH = 0;	//next largest height
	int steps = 0;	//count steps
	for(; coordX <= end; coordX++)
	{
		nextH = 0;
		for(no = 0; no < number; no++)
		{
			if(mouns[no].contain(coordX) > nextH)
				nextH = mouns[no].contain(coordX);
		}
		steps += abs(Height - nextH) + 1;
		Height = nextH;
	}
	delete[] inputs;
	free(mouns);
	return steps-1;
}



int main(int argc, char* argv[]) 
{
    const char* input[] = {
        "3\n1,3,2\n2,4,4\n6,7,5\n", //The giving example
        "1\n1,2,1\n",
        "2\n1,2,1\n2,3,2",
        "3\n1,2,1\n2,3,2\n3,6,1",
        "4\n1,2,1\n2,3,2\n3,6,1\n5,8,2",
        "5\n1,2,1\n2,3,2\n3,6,1\n5,8,2\n7,9,1",
        "1\n0,1,1",
        "2\n0,1,1\n2,4,3",
        "3\n0,1,1\n2,4,3\n3,5,1",
        "4\n0,1,1\n2,4,3\n3,5,1\n5,6,1",
        "5\n0,1,1\n2,4,3\n3,5,1\n5,6,1\n6,8,3",
        //TODO please add more test case here
        };
    int expectedSteps[] = {25, 4, 7, 10, 14, 15, 3, 12, 13, 14, 20};
    for (size_t i = 0; i < H_ARRAYSIZE(input); ++i)
    {
        assert(resolve(input[i]) == expectedSteps[i]);
    }
    printf( "All test OK!\n");
    return 0;
}
