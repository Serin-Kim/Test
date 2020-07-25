import java.util.Scanner;


class Player {
	Scanner scanner = new Scanner(System.in);
	public String name;  // 게임 참가자 이름 필
	public String word;
	
	public String getWordFromUser() {
		Scanner in = new Scanner(System.in);
		word = in.next();
		// System.out.println(word);
		return word;
	}
	
	public boolean checkSuccess(String lastWord) {
		int lastIndex = lastWord.length() - 1;
		char lastChar = lastWord.charAt(lastIndex);
		char firstChar = word.charAt(0); 
		
		if(lastChar == firstChar) {
			return true;
		}
		return false;
	}
	
	
}

public class WordGameApp {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String startWord = "아버지"; // 프로그램에서 첫 단어 설정해주기
		String inputWord;
		
		System.out.println("끝말잇기 게임을 시작합니다...");
		System.out.print("게임에 참가하는 인원은 몇명입니까>> ");
		int number = scanner.nextInt();
		
		Player [] play = new Player[number];
		
		for(int i=0; i<number; i++) {
			System.out.println("참가자의 이름을 입력하세요>>");
			play[i] = new Player(); 
			play[i].name = scanner.next();
		}
		System.out.println("시작하는 단어는 아버지입니다");
		
		int i=0, j=0;
		
		while(true) {
			j = i % number;
			System.out.print(play[j].name + ">> ");
			inputWord = play[j].getWordFromUser();
			boolean willContinue = play[j].checkSuccess(startWord);
			if (willContinue == false) {
				System.out.println(play[j].name + "이(가) 졌습니다.");
				break;
			}
			startWord = inputWord;
			i++;
		}
		
	}
	

}
