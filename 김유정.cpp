extern void my_push(int s);
extern int my_pop(int s);
extern void enqueue(void);

int item, compare;
void test_main(void) {
    /*
    0번은 생성스택이며 빈스택
    1번~9번은 정렬 스택

    1. 생성 스택에서 숫자를 뽑아 1~9번에 숫자를 한개씩 넣어준다. 9회 반복
    2. 생성 스택에서 숫자를 뽑는다.
    3. 생성에서 뽑은 값과 1~9의 마지막 값들을 비교하여 생성값이 작으면 그 스택에 넣어준다. //detail 절대값 차이가 적은 스택에 넣으면 좋지 않을까
    4. 1번~9번을 다 봤는데 넣을 곳이 없다
    --> 가장 sp가 작은 스택을 0번에 전부 옮겨놓고 그 수를 넣은후 다시 옮겨준다.
    //10000번 반복
    5. 1~9번 각 스택의 끝을 보고 가장 작은 스택의 끝을 뽑아 queue에 넣는다.
    */
    for (int i = 0; i < 9; i++) {
        item = my_pop(0);
        my_push(i+1);
    }
    for(int i = 0;i<9992;i++){
        item = my_pop(0);
        my_push(0);
        for (int i = 1; i < 10; i++) {
            compare = my_pop(i);
            if (item < compare) { //끝보다 작나?
                my_push(i);
                my_pop(0);
                my_push(i);
                break;
            }
            if (i == 9) {//i가 9인데 아직 못했다는건 가능한 곳이 없다.
                int j = smallist_stack(); // 스택 크기가 가장 작은 스택 인덱스 
                if (j == 9) {
                    move_stack(); //어떻게
                    my_pop(0);
                    my_push(9);
                    move_stack();

                }
            }

        }
    }
}