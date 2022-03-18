using NUnit.Framework;

namespace BWTransform.Tests
{
    public class Tests
    {
        [TestCase("������������ �� ������ � ����� �, ��� ��� �������, ����� ������� ��������, �������� � ��������� �����. �� ������ ��� ����� ���-�� �������� � �����. ���-�� ����������� � ��� ��� �� �����, � ������ � ��� ��������� �����-�� ����� �����. �� ��� ����� �� ������ ������ ���� ��������������� ����� ����� � �������� �����������, ��� ���� ���� ������ �������� ��� ��������� � ������ ����, ���� �� � ����� �� �� �� ����, �, �������� �� ��� ����� ����������, �� � ������������� ��������� ������ � �����������.", ExpectedResult = "������������ �� ������ � ����� �, ��� ��� �������, ����� ������� ��������, �������� � ��������� �����. �� ������ ��� ����� ���-�� �������� � �����. ���-�� ����������� � ��� ��� �� �����, � ������ � ��� ��������� �����-�� ����� �����. �� ��� ����� �� ������ ������ ���� ��������������� ����� ����� � �������� �����������, ��� ���� ���� ������ �������� ��� ��������� � ������ ����, ���� �� � ����� �� �� �� ����, �, �������� �� ��� ����� ����������, �� � ������������� ��������� ������ � �����������.")]
        [TestCase("kr525u8ruwefJKDER5784RWUIEFJFKeUr3298pruo);ieadejoRU8293OEIFALJwr4;oie", ExpectedResult = "kr525u8ruwefJKDER5784RWUIEFJFKeUr3298pruo);ieadejoRU8293OEIFALJwr4;oie")]
        [TestCase("Simple text! Nothing more.", ExpectedResult = "Simple text! Nothing more.")]
        public string TransformWorks(string originalLine)
        {
            (string line, int lineNumber) = BWTransform.DirectBWT(originalLine);
            return BWTransform.ReverseBWT(line, lineNumber);
        }
    }
}