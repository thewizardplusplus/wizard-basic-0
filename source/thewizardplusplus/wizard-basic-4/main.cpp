#include "CompilerConsoleParameters.h"
#include "exceptions/UnspecifiedSourceFile.h"
#include "PreprocessorManager.h"
#include "LineTrimmer.h"
#include "EmptyLineDeleter.h"
#include "CommentDeleter.h"
#include "LanguageElements.h"
#include "AssemblerModule.h"
#include "Compiler.h"
#include "ExpressionCompiler.h"
#include "DeclareFunctionStatement.h"
#include "DefineStatement.h"
#include "LetStatement.h"
#include "IfStatement.h"
#include "EndStatement.h"
#include "LabelStatement.h"
#include "GoToStatement.h"
#include "FunctionCallStatement.h"
#include "GnuAssembler.h"
#include "../utils/Console.h"
#include <cstdlib>

using namespace thewizardplusplus::wizard_basic_4;
using namespace thewizardplusplus::wizard_basic_4::exceptions;
using namespace thewizardplusplus::utils;

int main(int number_of_arguments, char** arguments) {
	try {
		CompilerConsoleParameters compiler_console_parameters;
		compiler_console_parameters.set(arguments, number_of_arguments);
		if (compiler_console_parameters.getSourcePath().empty()) {
			throw UnspecifiedSourceFile();
		}

		PreprocessorManager::PreprocessorList preprocessors;
		preprocessors.push_back(new LineTrimmer());
		preprocessors.push_back(new CommentDeleter(LanguageElements
			::COMMENT_MARK));
		preprocessors.push_back(new EmptyLineDeleter());
		PreprocessorManager preprocessor_manager(preprocessors);

		CodeLines code_lines = preprocessor_manager.preprocess(
			compiler_console_parameters.getSourcePath());
		FinalState::Types final_state = compiler_console_parameters
			.getFinalState();
		if (final_state == FinalState::PREPROCESSED_CODE) {
			Console::information() << code_lines.toString();
			std::exit(EXIT_SUCCESS);
		}

		AssemblerModule assembler_module;
		StringList inbuilt_function = StringUtils::split(LanguageElements
			::INBUILT_FUNCTIONS, LanguageElements::INBUILT_FUNCTION_SEPARATOR,
			false);
		StringList::const_iterator i = inbuilt_function.begin();
		for (; i != inbuilt_function.end(); ++i) {
			assembler_module.addFunctionIdentifier(*i);
		}

		Compiler compiler(&assembler_module);
		compiler.addStatementCompiler(new DeclareFunctionStatement(&compiler));
		compiler.addStatementCompiler(new DefineStatement(&compiler));
		compiler.addStatementCompiler(new LetStatement(&compiler));
		compiler.addStatementCompiler(new IfStatement(&compiler));
		compiler.addStatementCompiler(new EndStatement(&compiler));
		compiler.addStatementCompiler(new LabelStatement(&compiler));
		compiler.addStatementCompiler(new GoToStatement(&compiler));
		compiler.setDefaultStatementCompiler(new FunctionCallStatement(
			&compiler));

		OperatorList operators;
		operators.push_back(Operator(LanguageElements::ADD_OPERATOR_TOKEN,
			LanguageElements::ADD_OPERATOR_PRECEDENCE, LanguageElements
			::ADD_OPERATOR_ASSOCIATIVITY));
		operators.push_back(Operator(LanguageElements::SUB_OPERATOR_TOKEN,
			LanguageElements::SUB_OPERATOR_PRECEDENCE, LanguageElements
			::SUB_OPERATOR_ASSOCIATIVITY));
		operators.push_back(Operator(LanguageElements::MUL_OPERATOR_TOKEN,
			LanguageElements::MUL_OPERATOR_PRECEDENCE, LanguageElements
			::MUL_OPERATOR_ASSOCIATIVITY));
		operators.push_back(Operator(LanguageElements::DIV_OPERATOR_TOKEN,
			LanguageElements::DIV_OPERATOR_PRECEDENCE, LanguageElements
			::DIV_OPERATOR_ASSOCIATIVITY));
		operators.push_back(Operator(LanguageElements::LESS_OPERATOR_TOKEN,
			LanguageElements::LESS_OPERATOR_PRECEDENCE, LanguageElements
			::LESS_OPERATOR_ASSOCIATIVITY));
		operators.push_back(Operator(LanguageElements::MORE_OPERATOR_TOKEN,
			LanguageElements::MORE_OPERATOR_PRECEDENCE, LanguageElements
			::MORE_OPERATOR_ASSOCIATIVITY));
		operators.push_back(Operator(LanguageElements::EQUAL_OPERATOR_TOKEN,
			LanguageElements::EQUAL_OPERATOR_PRECEDENCE, LanguageElements
			::EQUAL_OPERATOR_ASSOCIATIVITY));
		operators.push_back(Operator(LanguageElements::AND_OPERATOR_TOKEN,
			LanguageElements::AND_OPERATOR_PRECEDENCE, LanguageElements
			::AND_OPERATOR_ASSOCIATIVITY));
		operators.push_back(Operator(LanguageElements::OR_OPERATOR_TOKEN,
			LanguageElements::OR_OPERATOR_PRECEDENCE, LanguageElements
			::OR_OPERATOR_ASSOCIATIVITY));
		operators.push_back(Operator(LanguageElements::NOT_OPERATOR_TOKEN,
			LanguageElements::NOT_OPERATOR_PRECEDENCE, LanguageElements
			::NOT_OPERATOR_ASSOCIATIVITY));
		compiler.setExpressionCompiler(new ExpressionCompiler(&compiler,
			operators, LanguageElements::OPENING_BRACKET, LanguageElements
			::CLOSING_BRACKET, LanguageElements::FUNCTION_ARGUMENT_SEPARATOR));

		compiler.compile(code_lines);
		if (final_state == FinalState::BYTE_CODE) {
			Console::information() << assembler_module.getAssemblerCode()
				.toString();
			std::exit(EXIT_SUCCESS);
		}

		GnuAssembler assembler(&assembler_module);
		assembler.assemble(compiler_console_parameters.getOutputPath());
		if (final_state == FinalState::ASSEMBLER_CODE) {
			Console::information() << assembler.getAssemblerCode();
			std::exit(EXIT_SUCCESS);
		}
	} catch (const std::exception& exception) {
		Console::error() << exception.what();
		std::exit(EXIT_FAILURE);
	}
}
