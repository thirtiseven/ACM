using System ;
public class forbiddenzero_xiaowuc1 {
    public static void Main(string[] args) {
        int n = int.Parse(Console.ReadLine());
        while(true) {
            n++;
            string cand = n.ToString();
            if(!cand.Contains("0")) {
                break;
            }
        }
        Console.WriteLine(n);
    }
}
