
class names 
{
	static int[] value;
    	static int offset, count;
    	static int indexOf(int str[]) 
	{
        	int[] v1 = value, v2 = str;
        	int max = offset + count;
        	int start = offset;
		int i=start;
i:        	while (i < max ) 
		{
            		int n =5 , j = i, k = 0;
			i++;
            		while (n!= 0) 
			{
				n--;
                		if (v1[j] != v2[k])
				{
					j++;
					k++;
					System.out.println(i);
                    			continue i;
				}
            		} 
            		return i - offset;
        	}
        	return -1;
	}

	public static void main(String args[])
	{
		value=new int[6];
		int i;
		for(i=0;i<=5;i++)
		{
			int j=i;
			value[j]=i;
		}
		offset=0;
		count=6;
		int []arr={5,6,7,8,9,10};
		System.out.println(indexOf(arr));
	}
}


