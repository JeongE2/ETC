/*
extern void my_push(int s); //s 스택의 개수 1개 증가, 마지막 값 push 값으로 변경
extern int my_pop(int s); //s 스택의 개수 1개 감소, 마지막 값 뽑은 값으로 변경
extern void enqueue(void);
#define SIZE 10000

int item;
int data[10][2] = { {SIZE,0} }; // 스택의 개수, top값

void smallist_in() { //1~8 스택 top값을 비교에 가장 작은값 queue에 넣기 //detail 최솟값이 두개면 두개다 enqueue -> 아무런 효과도 없었다..
    int small, small_i = 0, same, wow;
    for (int i = 0; i < SIZE; i++) {
        small = 1024;
        same = -1;
        for (int j = 1; j < 10; j++) {
            if (data[j][0] == 0) {
                continue;
            }
            if (data[j][1] < small) {
                small = data[j][1];
                small_i = j;
            }
            ///*
            else if (data[j][1] == small) {
                same = j;
            }
        }
        my_pop(small_i);
        enqueue();
        item = my_pop(small_i); my_push(small_i);
        data[small_i][0]--;
        data[small_i][1] = item;

        if (same != -1) {
            my_pop(same);
            enqueue();
            item = my_pop(same); my_push(same);
            data[same][0]--;
            data[same][1] = item;
            i++;
        }
    }
}

void move_stack(int n) {//n번 스택을 0번 스택으로 이동
    for (int i = 0; i < data[n][0]; i++) {
        my_pop(n);
        my_push(0);
    }
    data[n][0] = 0;
    data[n][1] = -1;
}

void test_main(void) {
    while (1) { //9번 스택이 비어야지만 break 해서 끝낼 수 있다.
        for (int i = 1; i < 9; i++) {
            item = my_pop(0); //pop한뒤 top값을 알기위해선 pop push 필요 //근데 0번 스택의 마지막 값은 유지할 필요 없음
            data[0][0]--;
            my_push(i); //push 3종 세트
            data[i][0]++;
            data[i][1] = item;
        }
        int small_abs = 0, abs;
        for (int i = 0; i < SIZE - 8; i++) {
            abs = 1024;
            item = my_pop(0); data[0][0]--; //생성 스택에서 값 하나 뽑는다.
            for (int j = 1; j < 9; j++) { //detail 작으면서 절대값의 차이가 작은 스택에
                if (item <= data[j][1]) { //top 보다 작나?
                    if (abs > (data[j][1] - item)) { //절대값 차이가 기존보다 작나?
                        abs = data[j][1] - item;
                        small_abs = j;
                    }
                }
            }
            if (abs == 1024) {//아직 안바꼈다는건 가능한 곳이 없다.
                my_push(9); data[9][0]++; data[9][1] = item;
            }
            else {
                my_push(small_abs); data[small_abs][0]++; data[small_abs][1] = item;
            }
        }
        if (data[0][0] == 0 && data[9][0] <= 1) { //각 스택 top값을 비교에 가장 작은값 queue에 넣기
            smallist_in();
            break;
        }
        else {//1~8번 0번에 넣고 9번도 넣고 다시 반복 //detail 그냥 넣지말고 정렬해서 0에 넣자
            for (int i = 1; i < 10; i++) {
                move_stack(i);
            }
            data[0][0] = SIZE;
        }
    }
}
*/