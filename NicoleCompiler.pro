TARGET = nicole_compiler
TEMPLATE = app
CONFIG += console
CONFIG -= qt
HEADERS += \
	source/thewizard/utils/os.h \
	source/thewizard/utils/FileInfo.h \
	source/thewizard/utils/CommandLineArguments.h \
	source/thewizard/nicole_compiler/CompilerConsoleParameters.h \
	source/thewizard/nicole_compiler/PreprocessorManager.h \
	source/thewizard/nicole_compiler/Preprocessor.h \
	source/thewizard/nicole_compiler/CodeLines.h \
	source/thewizard/utils/StringConverterHelper.h \
	source/thewizard/utils/FormatterTextAlign.h \
	source/thewizard/utils/Formatter.h \
	source/thewizard/utils/ConsoleMessageType.h \
	source/thewizard/utils/Console.h \
	source/thewizard/utils/StringConverter.h \
	source/thewizard/nicole_compiler/exceptions/UnableToOpenSourceFile.h \
	source/thewizard/utils/StringSide.h \
	source/thewizard/nicole_compiler/EmptyLineDeleter.h \
	source/thewizard/nicole_compiler/LineTrimmer.h \
	source/thewizard/nicole_compiler/CommentDeleter.h \
	source/thewizard/nicole_compiler/Compiler.h \
	source/thewizard/nicole_compiler/StatementCompiler.h \
	source/thewizard/nicole_compiler/exceptions/CompileException.h \
	source/thewizard/nicole_compiler/exceptions/SeparatorNotFound.h \
	source/thewizard/nicole_compiler/exceptions/UnknownStatement.h \
	source/thewizard/nicole_compiler/TestStatement.h \
	source/thewizard/nicole_compiler/ExpressionCompiler.h \
	source/thewizard/utils/StringUtils.h \
	source/thewizard/utils/StringList.h \
	source/thewizard/nicole_compiler/Operator.h \
	source/thewizard/nicole_compiler/OperatorAssociativity.h \
	source/thewizard/nicole_compiler/OperatorList.h \
	source/thewizard/nicole_compiler/AssemblerModule.h \
	source/thewizard/nicole_compiler/exceptions/MissedFunctionArgumentSeparatorOrOpeningBracket.h \
	source/thewizard/nicole_compiler/exceptions/MissedOpeningBracket.h \
	source/thewizard/nicole_compiler/exceptions/MissedClosingBracket.h \
	source/thewizard/nicole_compiler/LetStatement.h \
	source/thewizard/nicole_compiler/exceptions/InvalidNumberOfCodeLineParts.h \
	source/thewizard/nicole_compiler/IfStatement.h \
	source/thewizard/nicole_compiler/EndStatement.h \
	source/thewizard/nicole_compiler/LabelStatement.h \
	source/thewizard/nicole_compiler/GoToStatement.h \
	source/thewizard/nicole_compiler/FunctionCallStatement.h \
	source/thewizard/nicole_compiler/DefineStatement.h \
	source/thewizard/nicole_compiler/exceptions/InvalidStringFormat.h \
	source/thewizard/nicole_compiler/exceptions/UnknownExpressionToken.h \
	source/thewizard/nicole_compiler/AssemblerMnemonic.h \
	source/thewizard/nicole_compiler/exceptions/UndefinedVariable.h \
	source/thewizard/nicole_compiler/exceptions/UndefinedFunction.h \
	source/thewizard/nicole_compiler/exceptions/EndWithoutIf.h \
	source/thewizard/nicole_compiler/exceptions/IfWithoutEnd.h \
	source/thewizard/nicole_compiler/exceptions/IdentifierConflictWithVariable.h \
	source/thewizard/nicole_compiler/exceptions/IdentifierConflictWithFunction.h \
	source/thewizard/nicole_compiler/exceptions/LabelConflictWithOtherLabel.h \
	source/thewizard/nicole_compiler/exceptions/LabelConflictWithConditionalJumps.h \
	source/thewizard/nicole_compiler/Assembler.h \
	source/thewizard/nicole_compiler/DeclareFunctionStatement.h \
	source/thewizard/nicole_compiler/exceptions/InvalidFunctionIdentifier.h \
	source/thewizard/utils/exceptions/InvalidCommandLineArguments.h \
	source/thewizard/utils/Version.h \
	source/thewizard/nicole_compiler/current_version.h \
	source/thewizard/nicole_compiler/LanguageElements.h \
	source/thewizard/nicole_compiler/GnuAssembler.h
SOURCES += \
	source/thewizard/nicole_compiler/main.cpp \
	source/thewizard/utils/FileInfo.cpp \
	source/thewizard/utils/CommandLineArguments.cpp \
	source/thewizard/nicole_compiler/CompilerConsoleParameters.cpp \
	source/thewizard/nicole_compiler/PreprocessorManager.cpp \
	source/thewizard/utils/StringConverterHelper.cpp \
	source/thewizard/utils/Formatter.cpp \
	source/thewizard/utils/Console.cpp \
	source/thewizard/nicole_compiler/exceptions/UnableToOpenSourceFile.cpp \
	source/thewizard/nicole_compiler/CodeLines.cpp \
	source/thewizard/nicole_compiler/EmptyLineDeleter.cpp \
	source/thewizard/nicole_compiler/LineTrimmer.cpp \
	source/thewizard/nicole_compiler/CommentDeleter.cpp \
	source/thewizard/nicole_compiler/Compiler.cpp \
	source/thewizard/nicole_compiler/StatementCompiler.cpp \
	source/thewizard/nicole_compiler/exceptions/CompileException.cpp \
	source/thewizard/nicole_compiler/exceptions/SeparatorNotFound.cpp \
	source/thewizard/nicole_compiler/exceptions/UnknownStatement.cpp \
	source/thewizard/nicole_compiler/TestStatement.cpp \
	source/thewizard/nicole_compiler/ExpressionCompiler.cpp \
	source/thewizard/utils/StringUtils.cpp \
	source/thewizard/utils/StringList.cpp \
	source/thewizard/nicole_compiler/Preprocessor.cpp \
	source/thewizard/nicole_compiler/Operator.cpp \
	source/thewizard/nicole_compiler/OperatorList.cpp \
	source/thewizard/nicole_compiler/AssemblerModule.cpp \
	source/thewizard/nicole_compiler/exceptions/MissedFunctionArgumentSeparatorOrOpeningBracket.cpp \
	source/thewizard/nicole_compiler/exceptions/MissedOpeningBracket.cpp \
	source/thewizard/nicole_compiler/exceptions/MissedClosingBracket.cpp \
	source/thewizard/nicole_compiler/LetStatement.cpp \
	source/thewizard/nicole_compiler/exceptions/InvalidNumberOfCodeLineParts.cpp \
	source/thewizard/nicole_compiler/IfStatement.cpp \
	source/thewizard/nicole_compiler/EndStatement.cpp \
	source/thewizard/nicole_compiler/LabelStatement.cpp \
	source/thewizard/nicole_compiler/GoToStatement.cpp \
	source/thewizard/nicole_compiler/FunctionCallStatement.cpp \
	source/thewizard/nicole_compiler/DefineStatement.cpp \
	source/thewizard/nicole_compiler/exceptions/InvalidStringFormat.cpp \
	source/thewizard/nicole_compiler/exceptions/UnknownExpressionToken.cpp \
	source/thewizard/nicole_compiler/AssemblerMnemonic.cpp \
	source/thewizard/nicole_compiler/exceptions/UndefinedVariable.cpp \
	source/thewizard/nicole_compiler/exceptions/UndefinedFunction.cpp \
	source/thewizard/nicole_compiler/exceptions/EndWithoutIf.cpp \
	source/thewizard/nicole_compiler/exceptions/IfWithoutEnd.cpp \
	source/thewizard/nicole_compiler/exceptions/IdentifierConflictWithVariable.cpp \
	source/thewizard/nicole_compiler/exceptions/IdentifierConflictWithFunction.cpp \
	source/thewizard/nicole_compiler/exceptions/LabelConflictWithOtherLabel.cpp \
	source/thewizard/nicole_compiler/exceptions/LabelConflictWithConditionalJumps.cpp \
	source/thewizard/nicole_compiler/Assembler.cpp \
	source/thewizard/nicole_compiler/DeclareFunctionStatement.cpp \
	source/thewizard/nicole_compiler/exceptions/InvalidFunctionIdentifier.cpp \
	source/thewizard/utils/exceptions/InvalidCommandLineArguments.cpp \
	source/thewizard/nicole_compiler/LanguageElements.cpp \
	source/thewizard/nicole_compiler/GnuAssembler.cpp
QMAKE_CXXFLAGS += -Wall -W -pedantic
OTHER_FILES += \
	docs/examples/maze.ni \
	docs/to_do.txt \
	docs/grammar.txt \
	docs/examples/pi.ni \
	docs/working_log.txt \
	docs/syntax_highlighting/nicole_kate.xml
