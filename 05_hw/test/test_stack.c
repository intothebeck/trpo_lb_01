#include "unity.h"
#include "stack.h"

// Инициализация тестируемого стека
Stack testStack;

// Перед каждым тестом
void setUp(void) {
    initStack(&testStack);
}

// После каждого теста
void tearDown(void) {
    destroyStack(&testStack);
}

// Тест: проверка инициализации стека
void test_StackInitialization(void) {
    TEST_ASSERT_TRUE(isEmpty(&testStack));
}

// Тест: добавление элемента в стек
void test_PushElement(void) {
    TEST_ASSERT_TRUE(push(&testStack, 42));
    TEST_ASSERT_FALSE(isEmpty(&testStack));
    TEST_ASSERT_EQUAL(42, getTop(&testStack)->data);
}

// Тест: извлечение элемента из стека
void test_PopElement(void) {
    int poppedValue = 0;
    push(&testStack, 42);
    TEST_ASSERT_TRUE(pop(&testStack, &poppedValue));
    TEST_ASSERT_EQUAL(42, poppedValue);
    TEST_ASSERT_TRUE(isEmpty(&testStack));
}

// Тест: извлечение из пустого стека
void test_PopEmptyStack(void) {
    int poppedValue = 0;
    TEST_ASSERT_FALSE(pop(&testStack, &poppedValue));
    TEST_ASSERT_TRUE(isEmpty(&testStack));
}

// Тест: поиск по индексу
void test_SearchByIndex(void) {
    push(&testStack, 10);
    push(&testStack, 20);
    push(&testStack, 30);

    Node* node = searchByIndex(&testStack, 1);
    TEST_ASSERT_NOT_NULL(node);
    TEST_ASSERT_EQUAL(20, node->data);

    TEST_ASSERT_NULL(searchByIndex(&testStack, 5)); // Индекс вне диапазона
}

// Тест: поиск по значению
void test_SearchByValue(void) {
    push(&testStack, 100);
    push(&testStack, 200);
    push(&testStack, 300);

    Node* node = searchByValue(&testStack, 200);
    TEST_ASSERT_NOT_NULL(node);
    TEST_ASSERT_EQUAL(200, node->data);

    TEST_ASSERT_NULL(searchByValue(&testStack, 999)); // Значение не найдено
}

// Тест: очистка стека
void test_DestroyStack(void) {
    push(&testStack, 1);
    push(&testStack, 2);
    push(&testStack, 3);

    destroyStack(&testStack);
    TEST_ASSERT_TRUE(isEmpty(&testStack));
}

// Тест: обработка NULL указателя в initStack
void test_InitStackNull(void) {
    initStack(NULL); // Просто проверяем, что программа не падает
}

// Тест: обработка NULL указателя в destroyStack
void test_DestroyStackNull(void) {
    destroyStack(NULL); // Просто проверяем, что программа не падает
}

// Тест: обработка NULL указателя в push
void test_PushNullStack(void) {
    TEST_ASSERT_FALSE(push(NULL, 42));
}

// Тест: обработка NULL указателя в pop
void test_PopNullStack(void) {
    int poppedValue = 0;
    TEST_ASSERT_FALSE(pop(NULL, &poppedValue));
}

// Тест: обработка NULL указателя в searchByValue
void test_SearchByValueNullStack(void) {
    TEST_ASSERT_NULL(searchByValue(NULL, 42));
}

// Тест: обработка NULL указателя в searchByIndex
void test_SearchByIndexNullStack(void) {
    TEST_ASSERT_NULL(searchByIndex(NULL, 0));
}

// Тест: работа traverseStack
void test_TraverseStack(void) {
    // Пока traverseStack только выводит на экран, тестируем без падения
    traverseStack(&testStack);

    // Добавим элементы и проверим, что traverseStack отрабатывает корректно
    push(&testStack, 1);
    push(&testStack, 2);
    traverseStack(&testStack); // Ожидается вывод: "Stack elements: 2 1"
}

// Тест: проверка isEmpty
void test_IsEmptyNullStack(void) {
    TEST_ASSERT_TRUE(isEmpty(NULL)); // NULL стек должен считаться пустым
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_StackInitialization);
    RUN_TEST(test_PushElement);
    RUN_TEST(test_PopElement);
    RUN_TEST(test_PopEmptyStack);
    RUN_TEST(test_SearchByIndex);
    RUN_TEST(test_SearchByValue);
    RUN_TEST(test_DestroyStack);
    RUN_TEST(test_InitStackNull);
    RUN_TEST(test_DestroyStackNull);
    RUN_TEST(test_PushNullStack);
    RUN_TEST(test_PopNullStack);
    RUN_TEST(test_SearchByValueNullStack);
    RUN_TEST(test_SearchByIndexNullStack);
    RUN_TEST(test_TraverseStack);
    RUN_TEST(test_IsEmptyNullStack);
    return UNITY_END();
}
