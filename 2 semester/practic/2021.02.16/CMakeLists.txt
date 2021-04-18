cmake_minimum_required(VERSION 2.8)	 # Проверка версии CMake.
										# Если версия установленой программы
										# старее указаной, произайдёт аварийный выход.

project(sort)			# Название проекта

add_library(sort SHARED bubble_sort.cpp Insertion_sort.cpp merge_sort.cpp selection_sort.cpp)	# Создание статической библиотеки с именем foo

add_executable(main main.cpp )	# Создает исполняемый файл с именем main

target_link_libraries(main sort)		# Линковка программы с библиотекой



