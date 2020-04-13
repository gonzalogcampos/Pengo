#------------------- NOTA DE GONZALO -----------------------
#    De momento como no tenemos mucho codigo podemos
# compilar todos los .cpp en un unico binario (modulos.a)
# pero supongo que lo suyo seria crear varios binarios segun
# grupos para agilizar la compilacion.


#Especificar donde se encuentran los ficheros cpp a compilar
target_sources(modulos PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/GameObject/Ice.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/GameObject/Pengo.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/GameObject/SnoBee.cpp"

    "${CMAKE_CURRENT_SOURCE_DIR}/GameState/PlayState.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/GameState/IntroState.cpp"

    "${CMAKE_CURRENT_SOURCE_DIR}/Render/Render.cpp"
    
    "${CMAKE_CURRENT_SOURCE_DIR}/Console.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Game.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Map.cpp"


)

#Y donde se encuentran los .h
target_include_directories(modulos PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/GameObject"
    "${CMAKE_CURRENT_SOURCE_DIR}/GameState"
    "${CMAKE_CURRENT_SOURCE_DIR}/Render"

)

