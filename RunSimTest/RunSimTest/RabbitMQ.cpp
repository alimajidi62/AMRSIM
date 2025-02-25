#include <iostream>
#include <string>
#include <amqpcpp.h>
#include <amqpcpp/linux_tcp.h>

class RabbitMQ {
public:
    RabbitMQ(const std::string& host, int port, const std::string& queueName)
        : host_(host), port_(port), queueName_(queueName), handler_(nullptr), connection_(nullptr), channel_(nullptr) {
        connect();
    }

    ~RabbitMQ() {
        disconnect();
    }

    void sendMessage(const std::string& message) {
        if (channel_) {
            channel_->publish("", queueName_, message);
        } else {
            std::cerr << "Channel is not initialized." << std::endl;
        }
    }

    void receiveMessage() {
        if (channel_) {
            channel_->consume(queueName_)
                .onReceived([this](const AMQP::Message &message, uint64_t deliveryTag, bool redelivered) {
                    std::cout << "Received message: " << message.body() << std::endl;
                    channel_->ack(deliveryTag);
                });
        } else {
            std::cerr << "Channel is not initialized." << std::endl;
        }
    }

private:
    void connect() {
        handler_ = new AMQP::LibEvHandler(loop_);
        connection_ = new AMQP::TcpConnection(handler_, AMQP::Address(host_, port_, AMQP::Login("guest", "guest"), "/"));
        channel_ = new AMQP::TcpChannel(connection_);
        channel_->declareQueue(queueName_);
    }

    void disconnect() {
        if (channel_) {
            delete channel_;
            channel_ = nullptr;
        }
        if (connection_) {
            delete connection_;
            connection_ = nullptr;
        }
        if (handler_) {
            delete handler_;
            handler_ = nullptr;
        }
    }

    std::string host_;
    int port_;
    std::string queueName_;
    AMQP::LibEvHandler* handler_;
    AMQP::TcpConnection* connection_;
    AMQP::TcpChannel* channel_;
    struct ev_loop* loop_ = EV_DEFAULT;
};