set(SRCS
    main.cpp
)

set(HDRS
    docu_parts.hpp
    html_generator.hpp

    i_docu_visitable.h
    i_docu_visitor.h
)

add_executable(docu_generator ${SRCS} ${HDRS})