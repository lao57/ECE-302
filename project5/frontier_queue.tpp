#include "frontier_queue.hpp"

// TODO implement the member functions here

template <typename T>
State<T> frontier_queue<T>::pop()
{

  State<T> popped = queue.front();
  queue[0] = queue.back();
  queue.pop_back();
  int index = 0;
  int left, right;
  int size = queue.size() - 1;
  while ((index * 2 + 1) <= size)
  {
    int newpos = index;
    left = index * 2 + 1;
    right = index * 2 + 2;
    if (queue[newpos].getFCost() > queue[left].getFCost())
    {
      newpos = left;
    }

    if (right <= size)
    {
      if (queue[newpos].getFCost() > queue[right].getFCost())
      {
        newpos = right;
      }
    }

    if (newpos != index)
    {
      std::swap(queue[index], queue[newpos]);
      index = newpos;
    }
    else
    {
      break;
    }
  }
  return popped;
}

template <typename T>
void frontier_queue<T>::push(const T &p, std::size_t cost, std::size_t heur)
{
  State<T> state(p, cost, heur);
  queue.push_back(state);
  int size = queue.size() - 1;
  int index = size;

  while (index > 0)
  {
    size_t parent = (index - 1) / 2;
    if (queue[index].getFCost() < queue[parent].getFCost())
    {
      std::swap(queue[index], queue[parent]);
      index = parent;
    }
    else
    {
      break;
    }
  }
}

template <typename T>
bool frontier_queue<T>::empty()
{

  return queue.empty();
}

template <typename T>
bool frontier_queue<T>::contains(const T &p)
{

  int len = queue.size();
  for (int i = 0; i < len; i++)
  {
    if (p == queue[i].getValue())
    {
      return true;
    }
  }

  return false;
}

template <typename T>
void frontier_queue<T>::replaceif(const T &p, std::size_t cost)
{
  int size = queue.size();
  for (int i = 0; i < size; i++)
  {
    if (queue[i].getValue() == p)
    {
      if (cost < queue[i].getFCost())
      {
        queue[i].updatePathCost(cost);
        State<T> tempstate = queue[i];
        queue.erase(queue.begin() + i);
        push(p, cost, tempstate.getFCost() - cost);
      }
    }
  }
}
