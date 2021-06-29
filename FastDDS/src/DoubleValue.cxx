// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file DoubleValue.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifdef _WIN32
// Remove linker warning LNK4221 on Visual Studio
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "DoubleValue.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>

DoubleValue::DoubleValue()
{
    // m_value com.eprosima.idl.parser.typecode.PrimitiveTypeCode@66d1af89
    m_value = 0.0;

}

DoubleValue::~DoubleValue()
{
}

DoubleValue::DoubleValue(
        const DoubleValue& x)
{
    m_value = x.m_value;
}

DoubleValue::DoubleValue(
        DoubleValue&& x)
{
    m_value = x.m_value;
}

DoubleValue& DoubleValue::operator =(
        const DoubleValue& x)
{

    m_value = x.m_value;

    return *this;
}

DoubleValue& DoubleValue::operator =(
        DoubleValue&& x)
{

    m_value = x.m_value;

    return *this;
}

size_t DoubleValue::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    return current_alignment - initial_alignment;
}

size_t DoubleValue::getCdrSerializedSize(
        const DoubleValue& data,
        size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;


    current_alignment += 8 + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);


    return current_alignment - initial_alignment;
}

void DoubleValue::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{

    scdr << m_value;

}

void DoubleValue::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{

    dcdr >> m_value;
}

/*!
 * @brief This function sets a value in member value
 * @param _value New value for member value
 */
void DoubleValue::value(
        double _value)
{
    m_value = _value;
}

/*!
 * @brief This function returns the value of member value
 * @return Value of member value
 */
double DoubleValue::value() const
{
    return m_value;
}

/*!
 * @brief This function returns a reference to member value
 * @return Reference to member value
 */
double& DoubleValue::value()
{
    return m_value;
}


size_t DoubleValue::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t current_align = current_alignment;



    return current_align;
}

bool DoubleValue::isKeyDefined()
{
    return false;
}

void DoubleValue::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
     
}