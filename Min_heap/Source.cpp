#include <vector>

struct MinHeap
{
	std::vector<int> mData;

	void insert(int data)
	{
		mData.push_back(data);
		int i = mData.size() - 1;

		while (i != 0)
		{
			int parentIndex = (i - 1) / 2;
			if (mData[i] < mData[parentIndex])
			{
				int temp = mData[i];
				mData[i] = mData[parentIndex];
				mData[parentIndex] = temp;

				i = (i - 1) / 2;
			}
			else break; 
		}
	}

	int extract_min()
	{
		int min = mData[0];
		mData[0] = mData[mData.size() - 1];
		mData.pop_back();

		int i = 0;
		while (i < mData.size())
		{
			int lesserChild = -1;
			int leftChildIndex = 2 * i + 1;
			int rightChildIndex = 2 * i + 2;

			if (leftChildIndex >= mData.size() && rightChildIndex >= mData.size()) break; 
			else if (leftChildIndex >= mData.size()) lesserChild = rightChildIndex;
			else if (rightChildIndex >= mData.size()) lesserChild = leftChildIndex;
			else if (mData[leftChildIndex] <= mData[rightChildIndex]) // neither right nor left child are out of range
			{
				lesserChild = leftChildIndex;
			}
			else lesserChild = rightChildIndex;

			if (mData[lesserChild] < mData[i])
			{
				int temp = mData[i];
				mData[i] = mData[lesserChild];
				mData[lesserChild] = temp;

				i = lesserChild; 
			}
			else break; 
		}
		return min; 
	}
};
