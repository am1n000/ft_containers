
				pointer new__data;
				if (n == 0)
					n = 1;
				if (n <= _capacity)
					return;
				new__data = _alloc.allocate(n);
				if (this->_capacity > 0)
					_alloc.deallocate(_data, _capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(new__data + i, *(_data + i));
				_capacity = n;
				this->_data = new__data;







				iterator temp = position;
				size_t count1 = position - this->begin();
				if (_capacity <= _size + n)
				{
					if (n < _size)
						reserve(_size * 2);
					else
						reserve(_size + n);
				}
				size_t i = 1;
				size_type nn = n;
				for (size_type m = this->end() - position ;m > 0; m--)
				{
					if (_size - 1 + nn >= _size)
						_alloc.construct(_data + _size - 1 + nn, *(_data + _size - i));
					else
						*(_data + _size - 1 + nn) = *(_data + _size - i);
					nn--;
					i++;
				}
				_size += n;
				for (;n > 0; n--)
					_alloc.construct(_data + count1 + n - 1, val);