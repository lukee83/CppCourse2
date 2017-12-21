#include "CA.h"

void CA::run(int gen /* = 1*/) 
{
	for (int a = 0; a < gen; ++a)
	{
		int tmp = *p;
		for (int i = 0; i < size; ++i)
		{
			char res;
			
			//tmp, *(p+i+1), *(p + i + 2)
			char sh = *(p+i+2) + 2*(*(p+i+1)) + 4*tmp;
			res = 1 & (rule >> sh);

			tmp = *(p + i + 1);
			*(p + i + 1) = res;
		}
	}
}