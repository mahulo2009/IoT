#include "DoubleValuePubSubTypes.h"

#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/topic/TypeSupport.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/publisher/DataWriterListener.hpp>

using namespace eprosima::fastdds::dds;

int main(
        int argc,
        char** argv)
{
    std::cout << "Starting publisher." << std::endl;

    DomainParticipantQos participantQos;
    participantQos.name("Participant_publisher");

    DomainParticipant* participant_ = DomainParticipantFactory::get_instance()->create_participant(0, participantQos);

    // Register the Type
    TypeSupport type_(new DoubleValuePubSubType());
    type_.register_type(participant_);

    // Create the publications Topic    
    Topic* topic1_ = participant_->create_topic("DoubleValueTopic1", "DoubleValue", TOPIC_QOS_DEFAULT);
    Topic* topic2_ = participant_->create_topic("DoubleValueTopic2", "DoubleValue", TOPIC_QOS_DEFAULT);

    // Create the Publisher
    Publisher* publisher_ = participant_->create_publisher(PUBLISHER_QOS_DEFAULT, nullptr);

    // Create the DataWriter
    DataWriter* writer1_ = publisher_->create_datawriter(topic1_, DATAWRITER_QOS_DEFAULT, nullptr);
    DataWriter* writer2_ = publisher_->create_datawriter(topic2_, DATAWRITER_QOS_DEFAULT, nullptr);

    DoubleValue value_;
    while (true)
    {
        value_.value(1.0);
        writer1_->write(&value_);
        value_.value(2.0);
        writer2_->write(&value_);

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return 0;
}
