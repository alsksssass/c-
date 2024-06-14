#pragma once

template <typename T , typename P>
void iter(T *arr,unsigned int len, P point){
	if(!arr || len == 0)
		return;
	for(unsigned int i = 0; i < len; i++)
	{
		point(arr[i]);
	}
}