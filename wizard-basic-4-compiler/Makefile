SOURCE = source/thewizardplusplus/
SOURCE_UTILS = $(SOURCE)utils/
SOURCE_UTILS_EXCEPTIONS = $(SOURCE_UTILS)exceptions/
SOURCE_COMPILER = $(SOURCE)wizard-basic-4/
SOURCE_COMPILER_EXCEPTIONS = $(SOURCE_COMPILER)exceptions/
OBJECTS = \
	$(SOURCE_UTILS)StringUtils.o \
	$(SOURCE_UTILS)StringList.o \
	$(SOURCE_UTILS)StringConverter.o \
	$(SOURCE_UTILS)Formatter.o \
	$(SOURCE_UTILS)FileInfo.o \
	$(SOURCE_UTILS)Console.o \
	$(SOURCE_UTILS)CommandLineArguments.o \
	$(SOURCE_UTILS_EXCEPTIONS)NullPointerToCommandLineArgument.o \
	$(SOURCE_UTILS_EXCEPTIONS)NullPointerToArrayOfCommandLineArguments.o \
	$(SOURCE_UTILS_EXCEPTIONS)InvalidNumberOfCommandLineArguments.o \
	$(SOURCE_COMPILER)StatementCompiler.o \
	$(SOURCE_COMPILER)PreprocessorManager.o \
	$(SOURCE_COMPILER)Preprocessor.o \
	$(SOURCE_COMPILER)OperatorList.o \
	$(SOURCE_COMPILER)Operator.o \
	$(SOURCE_COMPILER)main.o \
	$(SOURCE_COMPILER)LineTrimmer.o \
	$(SOURCE_COMPILER)LetStatement.o \
	$(SOURCE_COMPILER)LanguageElements.o \
	$(SOURCE_COMPILER)LabelStatement.o \
	$(SOURCE_COMPILER)IfStatement.o \
	$(SOURCE_COMPILER)GoToStatement.o \
	$(SOURCE_COMPILER)GnuAssembler.o \
	$(SOURCE_COMPILER)FunctionInfo.o \
	$(SOURCE_COMPILER)FunctionCallStatement.o \
	$(SOURCE_COMPILER)FinalState.o \
	$(SOURCE_COMPILER)ExpressionCompiler.o \
	$(SOURCE_COMPILER)EndStatement.o \
	$(SOURCE_COMPILER)EmptyLineDeleter.o \
	$(SOURCE_COMPILER)DefineStatement.o \
	$(SOURCE_COMPILER)CompilerConsoleParameters.o \
	$(SOURCE_COMPILER)Compiler.o \
	$(SOURCE_COMPILER)CommentDeleter.o \
	$(SOURCE_COMPILER)CodeLines.o \
	$(SOURCE_COMPILER)Builder.o \
	$(SOURCE_COMPILER)AssemblerModule.o \
	$(SOURCE_COMPILER)AssemblerMnemonic.o \
	$(SOURCE_COMPILER)AssemblerCode.o \
	$(SOURCE_COMPILER)Assembler.o \
	$(SOURCE_COMPILER_EXCEPTIONS)UnspecifiedSourceFile.o \
	$(SOURCE_COMPILER_EXCEPTIONS)UnknownStatement.o \
	$(SOURCE_COMPILER_EXCEPTIONS)UnknownFinalState.o \
	$(SOURCE_COMPILER_EXCEPTIONS)UnknownExpressionToken.o \
	$(SOURCE_COMPILER_EXCEPTIONS)UnknownCommandLineOption.o \
	$(SOURCE_COMPILER_EXCEPTIONS)UndefinedVariable.o \
	$(SOURCE_COMPILER_EXCEPTIONS)UndefinedFunction.o \
	$(SOURCE_COMPILER_EXCEPTIONS)UnableToOpenSourceFile.o \
	$(SOURCE_COMPILER_EXCEPTIONS)SeparatorNotFound.o \
	$(SOURCE_COMPILER_EXCEPTIONS)MissedOpeningBracket.o \
	$(SOURCE_COMPILER_EXCEPTIONS)MissedFunctionArgumentSeparatorOrOpeningBracket.o \
	$(SOURCE_COMPILER_EXCEPTIONS)MissedClosingBracket.o \
	$(SOURCE_COMPILER_EXCEPTIONS)LabelConflictWithOtherLabel.o \
	$(SOURCE_COMPILER_EXCEPTIONS)LabelConflictWithConditionalJumps.o \
	$(SOURCE_COMPILER_EXCEPTIONS)InvalidStringFormat.o \
	$(SOURCE_COMPILER_EXCEPTIONS)InvalidNumberOfCodeLineParts.o \
	$(SOURCE_COMPILER_EXCEPTIONS)IfWithoutEnd.o \
	$(SOURCE_COMPILER_EXCEPTIONS)IdentifierConflictWithVariable.o \
	$(SOURCE_COMPILER_EXCEPTIONS)IdentifierConflictWithFunction.o \
	$(SOURCE_COMPILER_EXCEPTIONS)FailedOpenTemporaryFileException.o \
	$(SOURCE_COMPILER_EXCEPTIONS)EndWithoutIf.o \
	$(SOURCE_COMPILER_EXCEPTIONS)CompileException.o \
	$(SOURCE_COMPILER_EXCEPTIONS)AttemptToConstantChange.o \
	$(SOURCE_COMPILER_EXCEPTIONS)AssemblingOrLinkingException.o
BUILD = ../build/
CXXFLAGS += -std=c++03 -Wpedantic -Wall -Wextra -O3

.PHONY: clean

main: $(OBJECTS)
	mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) -o $(BUILD)wb4 $(OBJECTS) $(LDFLAGS)

clean:
	find . -name "*.o" -type f -delete
