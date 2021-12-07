import java.util.Scanner;
public class Leaky_bucket {
	public static void main(String[] args) {
		int i,bucket_size=0,transmission_rate=0,seconds=0,incoming_packets=0,packets_accepted=0,packets_discarded=0,packets_sent=999,packets_left=0;
		Scanner sc= new Scanner(System.in);
		System.out.println("Enter the bucket size (in packets)");
		bucket_size=sc.nextInt();
		System.out.println("Enter the transmission rate (in packets/sec)");
		transmission_rate=sc.nextInt();
		System.out.println("Enter the total time for sending packets (in sec)");
		seconds=sc.nextInt();
		int packet_sizes[]=new int[seconds];
		for(i=0;i<seconds;i++) {
			System.out.println("Enter the number of packets sent at second "+(i+1));
			packet_sizes[i]=sc.nextInt();
		}
		System.out.println("Second\tIncoming packets\tAccepted packets\tDiscarded packets\tPackets sent\tPackets left in the bucket");
		for(i=0;packets_left!=0||packets_sent>transmission_rate;i++,incoming_packets=0,packets_accepted=0,packets_discarded=0) {
			if(i<seconds){
				incoming_packets=packet_sizes[i];
				if(bucket_size>(incoming_packets+packets_left)) {
					packets_accepted=(incoming_packets+packets_left);
					packets_left=packets_accepted;
				}
				else{
					packets_discarded=incoming_packets+packets_left-bucket_size;
					packets_left=bucket_size;
					packets_accepted=incoming_packets-packets_discarded;
				}
			}
			if(packets_left>transmission_rate) {
				packets_left=packets_left-transmission_rate;
				packets_sent=transmission_rate;
			}
			else {
				packets_sent=packets_left;
				packets_left=0;
			}
			System.out.println("   "+(i+1)+"\t\t"+incoming_packets+"\t\t\t"+packets_accepted+"\t\t\t"+packets_discarded+"\t\t\t"+packets_sent+"\t\t    "+packets_left);
		}
		sc.close();
	}
}
