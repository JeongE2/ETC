/*
extern void my_push(int s); //s ������ ���� 1�� ����, ������ �� push ������ ����
extern int my_pop(int s); //s ������ ���� 1�� ����, ������ �� ���� ������ ����
extern void enqueue(void);
#define SIZE 10000

int item;
int data[10][2] = { {SIZE,0} }; // ������ ����, top��

void smallist_in() { //1~8 ���� top���� �񱳿� ���� ������ queue�� �ֱ� //detail �ּڰ��� �ΰ��� �ΰ��� enqueue -> �ƹ��� ȿ���� ������..
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

void move_stack(int n) {//n�� ������ 0�� �������� �̵�
    for (int i = 0; i < data[n][0]; i++) {
        my_pop(n);
        my_push(0);
    }
    data[n][0] = 0;
    data[n][1] = -1;
}

void test_main(void) {
    while (1) { //9�� ������ �������� break �ؼ� ���� �� �ִ�.
        for (int i = 1; i < 9; i++) {
            item = my_pop(0); //pop�ѵ� top���� �˱����ؼ� pop push �ʿ� //�ٵ� 0�� ������ ������ ���� ������ �ʿ� ����
            data[0][0]--;
            my_push(i); //push 3�� ��Ʈ
            data[i][0]++;
            data[i][1] = item;
        }
        int small_abs = 0, abs;
        for (int i = 0; i < SIZE - 8; i++) {
            abs = 1024;
            item = my_pop(0); data[0][0]--; //���� ���ÿ��� �� �ϳ� �̴´�.
            for (int j = 1; j < 9; j++) { //detail �����鼭 ���밪�� ���̰� ���� ���ÿ�
                if (item <= data[j][1]) { //top ���� �۳�?
                    if (abs > (data[j][1] - item)) { //���밪 ���̰� �������� �۳�?
                        abs = data[j][1] - item;
                        small_abs = j;
                    }
                }
            }
            if (abs == 1024) {//���� �ȹٲ��ٴ°� ������ ���� ����.
                my_push(9); data[9][0]++; data[9][1] = item;
            }
            else {
                my_push(small_abs); data[small_abs][0]++; data[small_abs][1] = item;
            }
        }
        if (data[0][0] == 0 && data[9][0] <= 1) { //�� ���� top���� �񱳿� ���� ������ queue�� �ֱ�
            smallist_in();
            break;
        }
        else {//1~8�� 0���� �ְ� 9���� �ְ� �ٽ� �ݺ� //detail �׳� �������� �����ؼ� 0�� ����
            for (int i = 1; i < 10; i++) {
                move_stack(i);
            }
            data[0][0] = SIZE;
        }
    }
}
*/