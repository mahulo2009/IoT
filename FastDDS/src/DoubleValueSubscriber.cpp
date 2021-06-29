#include "DoubleValuePubSubTypes.h"

#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/subscriber/DataReaderListener.hpp>
#include <fastdds/dds/subscriber/qos/DataReaderQos.hpp>
#include <fastdds/dds/subscriber/SampleInfo.hpp>

using namespace eprosima::fastdds::dds;

class SubListener : public DataReaderListener 
{
        void on_data_available(
                DataReader* reader) override
        {
            SampleInfo info;
            if (reader->take_next_sample(&value_, &info) == ReturnCode_t::RETCODE_OK)
            {
                if (info.valid_data)
                {
                    
                    std::cout << "Message: " << value_.value() 
                                << " RECEIVED." << std::endl;
                }
            }
        }

        DoubleValue value_;

} listener_;

int main(
        int argc,
        char** argv)
{
    std::cout << "Starting subscriber." << std::endl;

    DomainParticipantQos participantQos;
    participantQos.name("Participant_subscriber");

    DomainParticipant* participant_ = DomainParticipantFactory::get_instance()->create_participant(0, participantQos);

    // Register the Type
    TypeSupport type_(new DoubleValuePubSubType());
    type_.register_type(participant_);

    // Create the subscriptions Topic
    Topic* topic1_ =  participant_->create_topic("doubleMonitor1", "DoubleValue", TOPIC_QOS_DEFAULT);
    //Topic* topic2_ =  participant_->create_topic("DoubleValueTopic2", "DoubleValue", TOPIC_QOS_DEFAULT);

    // Create the Subscriber
    Subscriber * subscriber_ = participant_->create_subscriber(SUBSCRIBER_QOS_DEFAULT, nullptr);
    
    // Create the DataReader
    DataReader * reader1_ = subscriber_->create_datareader(topic1_, DATAREADER_QOS_DEFAULT, &listener_);
    //DataReader * reader2_ = subscriber_->create_datareader(topic2_, DATAREADER_QOS_DEFAULT, &listener_);

    while(true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return 0;
}
