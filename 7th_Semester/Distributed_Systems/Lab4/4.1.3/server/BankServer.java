import java.sql.*;
import com.rabbitmq.client.*;
import com.rabbitmq.client.Connection;

/*
 * Execute:
 * java FactorialServer
 */
public class BankServer {
	private static final String RPC_QUEUE_NAME = "rpc_queue";
	public static void main(String[] args) throws Exception {

		DatabaseUtils.initializeDatabase();
		Bank bank = new Bank();

		ConnectionFactory factory = new ConnectionFactory();
		factory.setHost("localhost");

		Connection connection = factory.newConnection();
		Channel channel = connection.createChannel();
		channel.queueDeclare(RPC_QUEUE_NAME, false, false, false, null);
		channel.queuePurge(RPC_QUEUE_NAME);

		channel.basicQos(1);

		System.out.println(" [x] Awaiting RPC requests");

		DeliverCallback deliverCallback = (consumerTag, delivery) -> {
			AMQP.BasicProperties replyProps = new AMQP.BasicProperties
					.Builder()
					.correlationId(delivery.getProperties().getCorrelationId())
					.build();

			String response = "";
			try {
				String message = new String(delivery.getBody(), "UTF-8");
				System.out.println(message);
				if (message.matches("^LOGIN.*")) {
					response += bank.login(message);
				} else if (message.matches("^WITHDRAW.*")) {
					response += bank.withdraw(message);
				} else if (message.matches("^DEPOSIT.*")) {
					response += bank.deposit(message);
				} else if (message.matches("^BALANCE.*")) {
					response += bank.balance();
				}

			} catch (RuntimeException e) {
				System.out.println(" [.] " + e);
			} finally {
				channel.basicPublish("", delivery.getProperties().getReplyTo(), replyProps, response.getBytes("UTF-8"));
				channel.basicAck(delivery.getEnvelope().getDeliveryTag(), false);
			}
		};

		channel.basicConsume(RPC_QUEUE_NAME, false, deliverCallback, (consumerTag -> {}));
	}
}

