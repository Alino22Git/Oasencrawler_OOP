#ifndef PERSON_H
#define PERSON_H
#include <iostream>


class Person
{
    public:
        Person(int size);
        void changePerson();
        void movePerson(int size);

        int GetX() const;
        int GetY() const;
        int GetType() const;

    protected:

    private:
        int type;
        int x;
        int y;
};

#endif // PERSON_H
