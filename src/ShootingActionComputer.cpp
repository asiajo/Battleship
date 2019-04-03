#include "../include/ShootingActionComputer.hpp"
#include <iostream>

std::pair <int, int> ShootingActionComputer::computerShot(const Board& board) const
{
    if(!_unshotShip.empty())
    {
        // need to be simplified after implementation of correct user input
        if (_unshotShip.size() > 1)
        {
            if(_unshotShip[0].first == _unshotShip[1].first)
            {
                std::pair <int, int> v = checkVertical(board);
                if(v.first != -1) return v;
                return checkHorizontal(board);

            }
            else if(_unshotShip[0].second == _unshotShip[1].second)
            {
                std::pair <int, int> h = checkHorizontal(board);
                if(h.first != -1) return h;
                return checkVertical(board);
            }
        }
        else
        {
            std::pair <int, int> h = checkHorizontal(board);
            std::pair <int, int> v = checkVertical(board);
            return h.first > v.first ? h : v;
        }
    }
    
    bool flag = false;
    int x, y;
    while (!flag)
    {
        x = (rand() %10)+1;
        y = (rand() %10)+1;
        if(board.getFieldInfo(x,y) <= 1)
            flag = true;
    }
    return std::make_pair(x, y);
}

std::pair <int, int> ShootingActionComputer::checkHorizontal(const Board& board) const 
{
    for(auto elem : _unshotShip)
    {
        if (board.getFieldInfo(elem.first -1, elem.second) <= 1 && elem.first -1 != 0                       ) return std::make_pair(elem.first -1, elem.second);
        if (board.getFieldInfo(elem.first +1, elem.second) <= 1 && elem.first +1 != board.getFieldSize()-1  ) return std::make_pair(elem.first +1, elem.second);
    }
    return std::make_pair(-1, -1);
}

std::pair <int, int> ShootingActionComputer::checkVertical(const Board& board) const 
{
    for(auto elem : _unshotShip)
    {
        if (board.getFieldInfo(elem.first, elem.second -1) <= 1 && elem.second -1 != 0                      ) return std::make_pair(elem.first, elem.second -1);
        if (board.getFieldInfo(elem.first, elem.second +1) <= 1 && elem.second +1 != board.getFieldSize()-1 ) return std::make_pair(elem.first, elem.second +1);
    }
    return std::make_pair(-1, -1);
}

void ShootingActionComputer::addUnshotShip(std::pair <int, int> shipPart)
{
    _unshotShip.push_back(shipPart);
}

void ShootingActionComputer::clearShotShip()
{
    _unshotShip.clear();
}