


int main(void)
{
    int *stacks = new int[12];
    int loc1 = 0;
    int loc2 = 4;
    int loc3 = 8;

    //if pushing to any number in the stack:
    stacks[loc1] = 3;
    loc1++;

    //if popping number
    int num = stacks[loc1];
    stacks[loc1] = -1;
    loc1--;
}


