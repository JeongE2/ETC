extern void my_push(int s);
extern int my_pop(int s);
extern void enqueue(void);

int item, compare;
void test_main(void) {
    /*
    0���� ���������̸� ����
    1��~9���� ���� ����

    1. ���� ���ÿ��� ���ڸ� �̾� 1~9���� ���ڸ� �Ѱ��� �־��ش�. 9ȸ �ݺ�
    2. ���� ���ÿ��� ���ڸ� �̴´�.
    3. �������� ���� ���� 1~9�� ������ ������ ���Ͽ� �������� ������ �� ���ÿ� �־��ش�. //detail ���밪 ���̰� ���� ���ÿ� ������ ���� ������
    4. 1��~9���� �� �ôµ� ���� ���� ����
    --> ���� sp�� ���� ������ 0���� ���� �Űܳ��� �� ���� ������ �ٽ� �Ű��ش�.
    //10000�� �ݺ�
    5. 1~9�� �� ������ ���� ���� ���� ���� ������ ���� �̾� queue�� �ִ´�.
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
            if (item < compare) { //������ �۳�?
                my_push(i);
                my_pop(0);
                my_push(i);
                break;
            }
            if (i == 9) {//i�� 9�ε� ���� ���ߴٴ°� ������ ���� ����.
                int j = smallist_stack(); // ���� ũ�Ⱑ ���� ���� ���� �ε��� 
                if (j == 9) {
                    move_stack(); //���
                    my_pop(0);
                    my_push(9);
                    move_stack();

                }
            }

        }
    }
}