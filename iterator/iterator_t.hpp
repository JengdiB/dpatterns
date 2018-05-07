namespace iter
{

template<typename T>
class IIterator;

template<typename T>
class IEnumarable
{
public:
	using iterator_type = IIterator<t>;

	iterator_type& begin() = 0;
	iterator_type& end()   = 0;

	const iterator_type& cbegin() const = 0;
	const iterator_type& cend() const   = 0;

};

template<typename T>
class IIterator
{
public:
	using this_type = IIterator<T>;

	this_type& next() = 0;
	
	const this_type& cnext() const = 0;
};

} // namespace iter
