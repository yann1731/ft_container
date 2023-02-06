namespace ft
{


class output_iterator_tag
{

};

class input_iterator_tag: public output_iterator_tag
{

};

class forward_iterator_tag: public input_iterator_tag
{

};

class bidirection_iterator_tag: public forward_iterator_tag
{

};

class random_access_iterato_tag: public bidirection_iterator_tag
{

};

}