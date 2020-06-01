#include <ctime>
#include "CalcForm.h"

using namespace Calc;

int main()
{
	srand((unsigned)time(NULL));
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew CalcForm);
}
