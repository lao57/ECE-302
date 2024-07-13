#include "queue.hpp"

template <typename T, typename L>
void Queue<T,L>::enqueue(const T& item)
{
  // TODO
  int pos = internal_list.getLength();
  internal_list.insert(pos, item);
}

template <typename T, typename L>
void Queue<T,L>::dequeue()
{
  internal_list.remove(0);
}

template <typename T, typename L>
T Queue<T,L>::peekFront()
{
  // TODO
  return internal_list.getEntry(0);
}

template <typename T, typename L>
bool Queue<T,L>::isEmpty() const
{
  // TODO
  return internal_list.isEmpty();
}

