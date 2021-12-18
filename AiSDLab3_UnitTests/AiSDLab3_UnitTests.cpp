#include "CppUnitTest.h"
#include "../AiSDLab3/BinaryHeap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AiSDLab3UnitTests
{
	TEST_CLASS(BinaryHeapTests)
	{
	public:

		TEST_METHOD(containsTest)
		{
			BinaryHeap heap;
			Assert::IsTrue(!heap.contains(0));
			heap.insert(1);
			heap.insert(5);
			heap.insert(3);
			heap.insert(2);
			heap.insert(80);
			heap.insert(-3);
			heap.insert(11);
			Assert::IsTrue(heap.contains(1));
			Assert::IsTrue(heap.contains(80));
			Assert::IsTrue(heap.contains(-3));
			Assert::IsTrue(!heap.contains(4));
			Assert::IsTrue(!heap.contains(-50));
			Assert::IsTrue(!heap.contains(0));
		}

		TEST_METHOD(insertTest) 
		{
			BinaryHeap heap;
			Iterator* iter = heap.create_bft_iterator();
			heap.insert(10);
			Assert::IsTrue(iter->next() == 10);
			heap.insert(11);
			delete iter;
			iter = heap.create_bft_iterator();
			Assert::IsTrue(iter->next() == 10);
			Assert::IsTrue(iter->next() == 11);
			heap.insert(9);
			delete iter;
			iter = heap.create_bft_iterator();
			Assert::IsTrue(iter->next() == 9);
			Assert::IsTrue(iter->next() == 11);
			Assert::IsTrue(iter->next() == 10);
			heap.insert(8);
			delete iter;
			iter = heap.create_bft_iterator();
			Assert::IsTrue(iter->next() == 8);
			Assert::IsTrue(iter->next() == 9);
			Assert::IsTrue(iter->next() == 10);
			Assert::IsTrue(iter->next() == 11);
			delete iter;
		}

		TEST_METHOD(removeTest) 
		{
			BinaryHeap heap;
			heap.insert(1);
			heap.remove(1);
			Assert::IsTrue(heap.get_size() == 0);
			for (int i = 1; i <= 10; i++) {
				heap.insert(i);
			}
			heap.remove(4);
			Iterator* iter = heap.create_bft_iterator();
			Assert::IsTrue(iter->next() == 1);
			Assert::IsTrue(iter->next() == 2);
			Assert::IsTrue(iter->next() == 3);
			Assert::IsTrue(iter->next() == 8);
			Assert::IsTrue(iter->next() == 5);
			Assert::IsTrue(iter->next() == 6);
			Assert::IsTrue(iter->next() == 7);
			Assert::IsTrue(iter->next() == 10);
			Assert::IsTrue(iter->next() == 9);
			delete iter;
			iter = heap.create_bft_iterator();
			heap.remove(1);
			Assert::IsTrue(iter->next() == 2);
			Assert::IsTrue(iter->next() == 5);
			Assert::IsTrue(iter->next() == 3);
			Assert::IsTrue(iter->next() == 8);
			Assert::IsTrue(iter->next() == 9);
			Assert::IsTrue(iter->next() == 6);
			Assert::IsTrue(iter->next() == 7);
			Assert::IsTrue(iter->next() == 10);
			delete iter;
			iter = heap.create_bft_iterator();
			heap.remove(10);
			Assert::IsTrue(iter->next() == 2);
			Assert::IsTrue(iter->next() == 5);
			Assert::IsTrue(iter->next() == 3);
			Assert::IsTrue(iter->next() == 8);
			Assert::IsTrue(iter->next() == 9);
			Assert::IsTrue(iter->next() == 6);
			Assert::IsTrue(iter->next() == 7);
			delete iter;
		}

		TEST_METHOD(create_dft_iteratorTest)
		{
			BinaryHeap heap;
			heap.insert(1);
			Iterator* iter = heap.create_dft_iterator();
			Assert::IsTrue(iter != nullptr);
		}

		TEST_METHOD(create_bft_iteratorTest)
		{
			BinaryHeap heap;
			heap.insert(1);
			Iterator* iter = heap.create_bft_iterator();
			Assert::IsTrue(iter != nullptr);
		}

		TEST_METHOD(dft_iterator_nextTest)
		{
			BinaryHeap heap;
			Iterator* iter = heap.create_dft_iterator();
			bool test = false;
			try
			{
				iter->next();
			}
			catch (std::out_of_range error)
			{
				test = true;
			}
			Assert::IsTrue(test);
			test = false;
			delete iter;
			iter = heap.create_dft_iterator();
			heap.insert(1);
			Assert::IsTrue(iter->next() == 1);
			try
			{
				iter->next();
			}
			catch (std::out_of_range error)
			{
				test = true;
			}
			Assert::IsTrue(test);
		}

		TEST_METHOD(dft_iterator_has_nextTest)
		{
			BinaryHeap heap;
			Iterator* iter = heap.create_dft_iterator();
			Assert::IsTrue(iter->has_next() == false);
			heap.insert(1);
			Assert::IsTrue(iter->has_next() == true);
			iter->next();
			Assert::IsTrue(iter->has_next() == false);
		}

		TEST_METHOD(bft_iterator_nextTest)
		{
			BinaryHeap heap;
			Iterator* iter = heap.create_bft_iterator();
			bool test = false;
			try
			{
				iter->next();
			}
			catch (std::out_of_range error)
			{
				test = true;
			}
			Assert::IsTrue(test);
			test = false;
			delete iter;
			iter = heap.create_dft_iterator();
			heap.insert(1);
			Assert::IsTrue(iter->next() == 1);
			try
			{
				iter->next();
			}
			catch (std::out_of_range error)
			{
				test = true;
			}
			Assert::IsTrue(test);
		}

		TEST_METHOD(bft_iterator_has_nextTest)
		{
			BinaryHeap heap;
			Iterator* iter = heap.create_bft_iterator();
			Assert::IsTrue(iter->has_next() == false);
			heap.insert(1);
			Assert::IsTrue(iter->has_next() == true);
			iter->next();
			Assert::IsTrue(iter->has_next() == false);
		}

		TEST_METHOD(capacity_increase_Test)
		{
			BinaryHeap heap;
			Iterator* iter = heap.create_bft_iterator();
			for (int i = 1; i <= 500; i++) {
				heap.insert(i);
			}
			for (int i = 1; i <= 500; i++) {
				Assert::IsTrue(iter->next() == i);
			}
			Assert::IsTrue(heap.get_size() == 500);
		}
	};
}