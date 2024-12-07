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

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_StackInitialization);
    RUN_TEST(test_PushElement);
    RUN_TEST(test_PopElement);
    RUN_TEST(test_PopEmptyStack);
    RUN_TEST(test_SearchByIndex);
    RUN_TEST(test_SearchByValue);
    RUN_TEST(test_DestroyStack);
    return UNITY_END();
}
