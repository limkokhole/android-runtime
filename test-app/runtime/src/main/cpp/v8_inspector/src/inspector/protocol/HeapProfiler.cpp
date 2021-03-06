// This file is generated by TypeBuilder_cpp.template.

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "src/inspector/protocol/HeapProfiler.h"

#include "src/inspector/protocol/Protocol.h"

#include "third_party/inspector_protocol/crdtp/cbor.h"
#include "third_party/inspector_protocol/crdtp/find_by_first.h"
#include "third_party/inspector_protocol/crdtp/serializer_traits.h"
#include "third_party/inspector_protocol/crdtp/span.h"

namespace v8_inspector {
namespace protocol {
namespace HeapProfiler {

// ------------- Enum values from types.

const char Metainfo::domainName[] = "HeapProfiler";
const char Metainfo::commandPrefix[] = "HeapProfiler.";
const char Metainfo::version[] = "1.3";

std::unique_ptr<SamplingHeapProfileNode> SamplingHeapProfileNode::fromValue(protocol::Value* value, ErrorSupport* errors)
{
    if (!value || value->type() != protocol::Value::TypeObject) {
        errors->AddError("object expected");
        return nullptr;
    }

    std::unique_ptr<SamplingHeapProfileNode> result(new SamplingHeapProfileNode());
    protocol::DictionaryValue* object = DictionaryValue::cast(value);
    errors->Push();
    protocol::Value* callFrameValue = object->get("callFrame");
    errors->SetName("callFrame");
    result->m_callFrame = ValueConversions<protocol::Runtime::CallFrame>::fromValue(callFrameValue, errors);
    protocol::Value* selfSizeValue = object->get("selfSize");
    errors->SetName("selfSize");
    result->m_selfSize = ValueConversions<double>::fromValue(selfSizeValue, errors);
    protocol::Value* idValue = object->get("id");
    errors->SetName("id");
    result->m_id = ValueConversions<int>::fromValue(idValue, errors);
    protocol::Value* childrenValue = object->get("children");
    errors->SetName("children");
    result->m_children = ValueConversions<protocol::Array<protocol::HeapProfiler::SamplingHeapProfileNode>>::fromValue(childrenValue, errors);
    errors->Pop();
    if (!errors->Errors().empty())
        return nullptr;
    return result;
}

std::unique_ptr<protocol::DictionaryValue> SamplingHeapProfileNode::toValue() const
{
    std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
    result->setValue("callFrame", ValueConversions<protocol::Runtime::CallFrame>::toValue(m_callFrame.get()));
    result->setValue("selfSize", ValueConversions<double>::toValue(m_selfSize));
    result->setValue("id", ValueConversions<int>::toValue(m_id));
    result->setValue("children", ValueConversions<protocol::Array<protocol::HeapProfiler::SamplingHeapProfileNode>>::toValue(m_children.get()));
    return result;
}

void SamplingHeapProfileNode::AppendSerialized(std::vector<uint8_t>* out) const {
    v8_crdtp::cbor::EnvelopeEncoder envelope_encoder;
    envelope_encoder.EncodeStart(out);
    out->push_back(v8_crdtp::cbor::EncodeIndefiniteLengthMapStart());
      v8_crdtp::SerializeField(v8_crdtp::SpanFrom("callFrame"), m_callFrame, out);
      v8_crdtp::SerializeField(v8_crdtp::SpanFrom("selfSize"), m_selfSize, out);
      v8_crdtp::SerializeField(v8_crdtp::SpanFrom("id"), m_id, out);
      v8_crdtp::SerializeField(v8_crdtp::SpanFrom("children"), m_children, out);
    out->push_back(v8_crdtp::cbor::EncodeStop());
    envelope_encoder.EncodeStop(out);
}

std::unique_ptr<SamplingHeapProfileNode> SamplingHeapProfileNode::clone() const
{
    ErrorSupport errors;
    return fromValue(toValue().get(), &errors);
}

std::unique_ptr<SamplingHeapProfileSample> SamplingHeapProfileSample::fromValue(protocol::Value* value, ErrorSupport* errors)
{
    if (!value || value->type() != protocol::Value::TypeObject) {
        errors->AddError("object expected");
        return nullptr;
    }

    std::unique_ptr<SamplingHeapProfileSample> result(new SamplingHeapProfileSample());
    protocol::DictionaryValue* object = DictionaryValue::cast(value);
    errors->Push();
    protocol::Value* sizeValue = object->get("size");
    errors->SetName("size");
    result->m_size = ValueConversions<double>::fromValue(sizeValue, errors);
    protocol::Value* nodeIdValue = object->get("nodeId");
    errors->SetName("nodeId");
    result->m_nodeId = ValueConversions<int>::fromValue(nodeIdValue, errors);
    protocol::Value* ordinalValue = object->get("ordinal");
    errors->SetName("ordinal");
    result->m_ordinal = ValueConversions<double>::fromValue(ordinalValue, errors);
    errors->Pop();
    if (!errors->Errors().empty())
        return nullptr;
    return result;
}

std::unique_ptr<protocol::DictionaryValue> SamplingHeapProfileSample::toValue() const
{
    std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
    result->setValue("size", ValueConversions<double>::toValue(m_size));
    result->setValue("nodeId", ValueConversions<int>::toValue(m_nodeId));
    result->setValue("ordinal", ValueConversions<double>::toValue(m_ordinal));
    return result;
}

void SamplingHeapProfileSample::AppendSerialized(std::vector<uint8_t>* out) const {
    v8_crdtp::cbor::EnvelopeEncoder envelope_encoder;
    envelope_encoder.EncodeStart(out);
    out->push_back(v8_crdtp::cbor::EncodeIndefiniteLengthMapStart());
      v8_crdtp::SerializeField(v8_crdtp::SpanFrom("size"), m_size, out);
      v8_crdtp::SerializeField(v8_crdtp::SpanFrom("nodeId"), m_nodeId, out);
      v8_crdtp::SerializeField(v8_crdtp::SpanFrom("ordinal"), m_ordinal, out);
    out->push_back(v8_crdtp::cbor::EncodeStop());
    envelope_encoder.EncodeStop(out);
}

std::unique_ptr<SamplingHeapProfileSample> SamplingHeapProfileSample::clone() const
{
    ErrorSupport errors;
    return fromValue(toValue().get(), &errors);
}

std::unique_ptr<SamplingHeapProfile> SamplingHeapProfile::fromValue(protocol::Value* value, ErrorSupport* errors)
{
    if (!value || value->type() != protocol::Value::TypeObject) {
        errors->AddError("object expected");
        return nullptr;
    }

    std::unique_ptr<SamplingHeapProfile> result(new SamplingHeapProfile());
    protocol::DictionaryValue* object = DictionaryValue::cast(value);
    errors->Push();
    protocol::Value* headValue = object->get("head");
    errors->SetName("head");
    result->m_head = ValueConversions<protocol::HeapProfiler::SamplingHeapProfileNode>::fromValue(headValue, errors);
    protocol::Value* samplesValue = object->get("samples");
    errors->SetName("samples");
    result->m_samples = ValueConversions<protocol::Array<protocol::HeapProfiler::SamplingHeapProfileSample>>::fromValue(samplesValue, errors);
    errors->Pop();
    if (!errors->Errors().empty())
        return nullptr;
    return result;
}

std::unique_ptr<protocol::DictionaryValue> SamplingHeapProfile::toValue() const
{
    std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
    result->setValue("head", ValueConversions<protocol::HeapProfiler::SamplingHeapProfileNode>::toValue(m_head.get()));
    result->setValue("samples", ValueConversions<protocol::Array<protocol::HeapProfiler::SamplingHeapProfileSample>>::toValue(m_samples.get()));
    return result;
}

void SamplingHeapProfile::AppendSerialized(std::vector<uint8_t>* out) const {
    v8_crdtp::cbor::EnvelopeEncoder envelope_encoder;
    envelope_encoder.EncodeStart(out);
    out->push_back(v8_crdtp::cbor::EncodeIndefiniteLengthMapStart());
      v8_crdtp::SerializeField(v8_crdtp::SpanFrom("head"), m_head, out);
      v8_crdtp::SerializeField(v8_crdtp::SpanFrom("samples"), m_samples, out);
    out->push_back(v8_crdtp::cbor::EncodeStop());
    envelope_encoder.EncodeStop(out);
}

std::unique_ptr<SamplingHeapProfile> SamplingHeapProfile::clone() const
{
    ErrorSupport errors;
    return fromValue(toValue().get(), &errors);
}

std::unique_ptr<AddHeapSnapshotChunkNotification> AddHeapSnapshotChunkNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
{
    if (!value || value->type() != protocol::Value::TypeObject) {
        errors->AddError("object expected");
        return nullptr;
    }

    std::unique_ptr<AddHeapSnapshotChunkNotification> result(new AddHeapSnapshotChunkNotification());
    protocol::DictionaryValue* object = DictionaryValue::cast(value);
    errors->Push();
    protocol::Value* chunkValue = object->get("chunk");
    errors->SetName("chunk");
    result->m_chunk = ValueConversions<String>::fromValue(chunkValue, errors);
    errors->Pop();
    if (!errors->Errors().empty())
        return nullptr;
    return result;
}

std::unique_ptr<protocol::DictionaryValue> AddHeapSnapshotChunkNotification::toValue() const
{
    std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
    result->setValue("chunk", ValueConversions<String>::toValue(m_chunk));
    return result;
}

void AddHeapSnapshotChunkNotification::AppendSerialized(std::vector<uint8_t>* out) const {
    v8_crdtp::cbor::EnvelopeEncoder envelope_encoder;
    envelope_encoder.EncodeStart(out);
    out->push_back(v8_crdtp::cbor::EncodeIndefiniteLengthMapStart());
      v8_crdtp::SerializeField(v8_crdtp::SpanFrom("chunk"), m_chunk, out);
    out->push_back(v8_crdtp::cbor::EncodeStop());
    envelope_encoder.EncodeStop(out);
}

std::unique_ptr<AddHeapSnapshotChunkNotification> AddHeapSnapshotChunkNotification::clone() const
{
    ErrorSupport errors;
    return fromValue(toValue().get(), &errors);
}

std::unique_ptr<HeapStatsUpdateNotification> HeapStatsUpdateNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
{
    if (!value || value->type() != protocol::Value::TypeObject) {
        errors->AddError("object expected");
        return nullptr;
    }

    std::unique_ptr<HeapStatsUpdateNotification> result(new HeapStatsUpdateNotification());
    protocol::DictionaryValue* object = DictionaryValue::cast(value);
    errors->Push();
    protocol::Value* statsUpdateValue = object->get("statsUpdate");
    errors->SetName("statsUpdate");
    result->m_statsUpdate = ValueConversions<protocol::Array<int>>::fromValue(statsUpdateValue, errors);
    errors->Pop();
    if (!errors->Errors().empty())
        return nullptr;
    return result;
}

std::unique_ptr<protocol::DictionaryValue> HeapStatsUpdateNotification::toValue() const
{
    std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
    result->setValue("statsUpdate", ValueConversions<protocol::Array<int>>::toValue(m_statsUpdate.get()));
    return result;
}

void HeapStatsUpdateNotification::AppendSerialized(std::vector<uint8_t>* out) const {
    v8_crdtp::cbor::EnvelopeEncoder envelope_encoder;
    envelope_encoder.EncodeStart(out);
    out->push_back(v8_crdtp::cbor::EncodeIndefiniteLengthMapStart());
      v8_crdtp::SerializeField(v8_crdtp::SpanFrom("statsUpdate"), m_statsUpdate, out);
    out->push_back(v8_crdtp::cbor::EncodeStop());
    envelope_encoder.EncodeStop(out);
}

std::unique_ptr<HeapStatsUpdateNotification> HeapStatsUpdateNotification::clone() const
{
    ErrorSupport errors;
    return fromValue(toValue().get(), &errors);
}

std::unique_ptr<LastSeenObjectIdNotification> LastSeenObjectIdNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
{
    if (!value || value->type() != protocol::Value::TypeObject) {
        errors->AddError("object expected");
        return nullptr;
    }

    std::unique_ptr<LastSeenObjectIdNotification> result(new LastSeenObjectIdNotification());
    protocol::DictionaryValue* object = DictionaryValue::cast(value);
    errors->Push();
    protocol::Value* lastSeenObjectIdValue = object->get("lastSeenObjectId");
    errors->SetName("lastSeenObjectId");
    result->m_lastSeenObjectId = ValueConversions<int>::fromValue(lastSeenObjectIdValue, errors);
    protocol::Value* timestampValue = object->get("timestamp");
    errors->SetName("timestamp");
    result->m_timestamp = ValueConversions<double>::fromValue(timestampValue, errors);
    errors->Pop();
    if (!errors->Errors().empty())
        return nullptr;
    return result;
}

std::unique_ptr<protocol::DictionaryValue> LastSeenObjectIdNotification::toValue() const
{
    std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
    result->setValue("lastSeenObjectId", ValueConversions<int>::toValue(m_lastSeenObjectId));
    result->setValue("timestamp", ValueConversions<double>::toValue(m_timestamp));
    return result;
}

void LastSeenObjectIdNotification::AppendSerialized(std::vector<uint8_t>* out) const {
    v8_crdtp::cbor::EnvelopeEncoder envelope_encoder;
    envelope_encoder.EncodeStart(out);
    out->push_back(v8_crdtp::cbor::EncodeIndefiniteLengthMapStart());
      v8_crdtp::SerializeField(v8_crdtp::SpanFrom("lastSeenObjectId"), m_lastSeenObjectId, out);
      v8_crdtp::SerializeField(v8_crdtp::SpanFrom("timestamp"), m_timestamp, out);
    out->push_back(v8_crdtp::cbor::EncodeStop());
    envelope_encoder.EncodeStop(out);
}

std::unique_ptr<LastSeenObjectIdNotification> LastSeenObjectIdNotification::clone() const
{
    ErrorSupport errors;
    return fromValue(toValue().get(), &errors);
}

std::unique_ptr<ReportHeapSnapshotProgressNotification> ReportHeapSnapshotProgressNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
{
    if (!value || value->type() != protocol::Value::TypeObject) {
        errors->AddError("object expected");
        return nullptr;
    }

    std::unique_ptr<ReportHeapSnapshotProgressNotification> result(new ReportHeapSnapshotProgressNotification());
    protocol::DictionaryValue* object = DictionaryValue::cast(value);
    errors->Push();
    protocol::Value* doneValue = object->get("done");
    errors->SetName("done");
    result->m_done = ValueConversions<int>::fromValue(doneValue, errors);
    protocol::Value* totalValue = object->get("total");
    errors->SetName("total");
    result->m_total = ValueConversions<int>::fromValue(totalValue, errors);
    protocol::Value* finishedValue = object->get("finished");
    if (finishedValue) {
        errors->SetName("finished");
        result->m_finished = ValueConversions<bool>::fromValue(finishedValue, errors);
    }
    errors->Pop();
    if (!errors->Errors().empty())
        return nullptr;
    return result;
}

std::unique_ptr<protocol::DictionaryValue> ReportHeapSnapshotProgressNotification::toValue() const
{
    std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
    result->setValue("done", ValueConversions<int>::toValue(m_done));
    result->setValue("total", ValueConversions<int>::toValue(m_total));
    if (m_finished.isJust())
        result->setValue("finished", ValueConversions<bool>::toValue(m_finished.fromJust()));
    return result;
}

void ReportHeapSnapshotProgressNotification::AppendSerialized(std::vector<uint8_t>* out) const {
    v8_crdtp::cbor::EnvelopeEncoder envelope_encoder;
    envelope_encoder.EncodeStart(out);
    out->push_back(v8_crdtp::cbor::EncodeIndefiniteLengthMapStart());
      v8_crdtp::SerializeField(v8_crdtp::SpanFrom("done"), m_done, out);
      v8_crdtp::SerializeField(v8_crdtp::SpanFrom("total"), m_total, out);
      v8_crdtp::SerializeField(v8_crdtp::SpanFrom("finished"), m_finished, out);
    out->push_back(v8_crdtp::cbor::EncodeStop());
    envelope_encoder.EncodeStop(out);
}

std::unique_ptr<ReportHeapSnapshotProgressNotification> ReportHeapSnapshotProgressNotification::clone() const
{
    ErrorSupport errors;
    return fromValue(toValue().get(), &errors);
}

// ------------- Enum values from params.


// ------------- Frontend notifications.

void Frontend::addHeapSnapshotChunk(const String& chunk)
{
    if (!frontend_channel_)
        return;
    std::unique_ptr<AddHeapSnapshotChunkNotification> messageData = AddHeapSnapshotChunkNotification::create()
        .setChunk(chunk)
        .build();
    frontend_channel_->SendProtocolNotification(v8_crdtp::CreateNotification("HeapProfiler.addHeapSnapshotChunk", std::move(messageData)));
}

void Frontend::heapStatsUpdate(std::unique_ptr<protocol::Array<int>> statsUpdate)
{
    if (!frontend_channel_)
        return;
    std::unique_ptr<HeapStatsUpdateNotification> messageData = HeapStatsUpdateNotification::create()
        .setStatsUpdate(std::move(statsUpdate))
        .build();
    frontend_channel_->SendProtocolNotification(v8_crdtp::CreateNotification("HeapProfiler.heapStatsUpdate", std::move(messageData)));
}

void Frontend::lastSeenObjectId(int lastSeenObjectId, double timestamp)
{
    if (!frontend_channel_)
        return;
    std::unique_ptr<LastSeenObjectIdNotification> messageData = LastSeenObjectIdNotification::create()
        .setLastSeenObjectId(lastSeenObjectId)
        .setTimestamp(timestamp)
        .build();
    frontend_channel_->SendProtocolNotification(v8_crdtp::CreateNotification("HeapProfiler.lastSeenObjectId", std::move(messageData)));
}

void Frontend::reportHeapSnapshotProgress(int done, int total, Maybe<bool> finished)
{
    if (!frontend_channel_)
        return;
    std::unique_ptr<ReportHeapSnapshotProgressNotification> messageData = ReportHeapSnapshotProgressNotification::create()
        .setDone(done)
        .setTotal(total)
        .build();
    if (finished.isJust())
        messageData->setFinished(std::move(finished).takeJust());
    frontend_channel_->SendProtocolNotification(v8_crdtp::CreateNotification("HeapProfiler.reportHeapSnapshotProgress", std::move(messageData)));
}

void Frontend::resetProfiles()
{
    if (!frontend_channel_)
        return;
    frontend_channel_->SendProtocolNotification(v8_crdtp::CreateNotification("HeapProfiler.resetProfiles"));
}

void Frontend::flush()
{
    frontend_channel_->FlushProtocolNotifications();
}

void Frontend::sendRawNotification(std::unique_ptr<Serializable> notification)
{
    frontend_channel_->SendProtocolNotification(std::move(notification));
}

// --------------------- Dispatcher.

class DomainDispatcherImpl : public protocol::DomainDispatcher {
public:
    DomainDispatcherImpl(FrontendChannel* frontendChannel, Backend* backend)
        : DomainDispatcher(frontendChannel)
        , m_backend(backend) {}
    ~DomainDispatcherImpl() override { }

    using CallHandler = void (DomainDispatcherImpl::*)(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors);

    std::function<void(const v8_crdtp::Dispatchable&)> Dispatch(v8_crdtp::span<uint8_t> command_name) override;

    void addInspectedHeapObject(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors);
    void collectGarbage(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors);
    void disable(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors);
    void enable(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors);
    void getHeapObjectId(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors);
    void getObjectByHeapObjectId(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors);
    void getSamplingProfile(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors);
    void startSampling(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors);
    void startTrackingHeapObjects(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors);
    void stopSampling(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors);
    void stopTrackingHeapObjects(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors);
    void takeHeapSnapshot(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors);
 protected:
    Backend* m_backend;
};

namespace {
// This helper method with a static map of command methods (instance methods
// of DomainDispatcherImpl declared just above) by their name is used immediately below,
// in the DomainDispatcherImpl::Dispatch method.
DomainDispatcherImpl::CallHandler CommandByName(v8_crdtp::span<uint8_t> command_name) {
  static auto* commands = [](){
    auto* commands = new std::vector<std::pair<v8_crdtp::span<uint8_t>,
                              DomainDispatcherImpl::CallHandler>>{
    {
          v8_crdtp::SpanFrom("addInspectedHeapObject"),
          &DomainDispatcherImpl::addInspectedHeapObject
    },
    {
          v8_crdtp::SpanFrom("collectGarbage"),
          &DomainDispatcherImpl::collectGarbage
    },
    {
          v8_crdtp::SpanFrom("disable"),
          &DomainDispatcherImpl::disable
    },
    {
          v8_crdtp::SpanFrom("enable"),
          &DomainDispatcherImpl::enable
    },
    {
          v8_crdtp::SpanFrom("getHeapObjectId"),
          &DomainDispatcherImpl::getHeapObjectId
    },
    {
          v8_crdtp::SpanFrom("getObjectByHeapObjectId"),
          &DomainDispatcherImpl::getObjectByHeapObjectId
    },
    {
          v8_crdtp::SpanFrom("getSamplingProfile"),
          &DomainDispatcherImpl::getSamplingProfile
    },
    {
          v8_crdtp::SpanFrom("startSampling"),
          &DomainDispatcherImpl::startSampling
    },
    {
          v8_crdtp::SpanFrom("startTrackingHeapObjects"),
          &DomainDispatcherImpl::startTrackingHeapObjects
    },
    {
          v8_crdtp::SpanFrom("stopSampling"),
          &DomainDispatcherImpl::stopSampling
    },
    {
          v8_crdtp::SpanFrom("stopTrackingHeapObjects"),
          &DomainDispatcherImpl::stopTrackingHeapObjects
    },
    {
          v8_crdtp::SpanFrom("takeHeapSnapshot"),
          &DomainDispatcherImpl::takeHeapSnapshot
    },
    };
    return commands;
  }();
  return v8_crdtp::FindByFirst<DomainDispatcherImpl::CallHandler>(*commands, command_name, nullptr);
}
}  // namespace

std::function<void(const v8_crdtp::Dispatchable&)> DomainDispatcherImpl::Dispatch(v8_crdtp::span<uint8_t> command_name) {
  CallHandler handler = CommandByName(command_name);
  if (!handler) return nullptr;
  return [this, handler](const v8_crdtp::Dispatchable& dispatchable){
    std::unique_ptr<DictionaryValue> params =
        DictionaryValue::cast(protocol::Value::parseBinary(dispatchable.Params().data(),
        dispatchable.Params().size()));
    ErrorSupport errors;
    errors.Push();
    (this->*handler)(dispatchable, params.get(), &errors);
  };
}


void DomainDispatcherImpl::addInspectedHeapObject(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors)
{
    // Prepare input parameters.
    protocol::Value* heapObjectIdValue = params ? params->get("heapObjectId") : nullptr;
    errors->SetName("heapObjectId");
    String in_heapObjectId = ValueConversions<String>::fromValue(heapObjectIdValue, errors);
    if (MaybeReportInvalidParams(dispatchable, *errors)) return;

    std::unique_ptr<DomainDispatcher::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->addInspectedHeapObject(in_heapObjectId);
    if (response.IsFallThrough()) {
        channel()->FallThrough(dispatchable.CallId(), v8_crdtp::SpanFrom("HeapProfiler.addInspectedHeapObject"), dispatchable.Serialized());
        return;
    }
    if (weak->get())
        weak->get()->sendResponse(dispatchable.CallId(), response);
    return;
}

void DomainDispatcherImpl::collectGarbage(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors)
{

    std::unique_ptr<DomainDispatcher::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->collectGarbage();
    if (response.IsFallThrough()) {
        channel()->FallThrough(dispatchable.CallId(), v8_crdtp::SpanFrom("HeapProfiler.collectGarbage"), dispatchable.Serialized());
        return;
    }
    if (weak->get())
        weak->get()->sendResponse(dispatchable.CallId(), response);
    return;
}

void DomainDispatcherImpl::disable(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors)
{

    std::unique_ptr<DomainDispatcher::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->disable();
    if (response.IsFallThrough()) {
        channel()->FallThrough(dispatchable.CallId(), v8_crdtp::SpanFrom("HeapProfiler.disable"), dispatchable.Serialized());
        return;
    }
    if (weak->get())
        weak->get()->sendResponse(dispatchable.CallId(), response);
    return;
}

void DomainDispatcherImpl::enable(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors)
{

    std::unique_ptr<DomainDispatcher::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->enable();
    if (response.IsFallThrough()) {
        channel()->FallThrough(dispatchable.CallId(), v8_crdtp::SpanFrom("HeapProfiler.enable"), dispatchable.Serialized());
        return;
    }
    if (weak->get())
        weak->get()->sendResponse(dispatchable.CallId(), response);
    return;
}

void DomainDispatcherImpl::getHeapObjectId(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors)
{
    // Prepare input parameters.
    protocol::Value* objectIdValue = params ? params->get("objectId") : nullptr;
    errors->SetName("objectId");
    String in_objectId = ValueConversions<String>::fromValue(objectIdValue, errors);
    if (MaybeReportInvalidParams(dispatchable, *errors)) return;
    // Declare output parameters.
    String out_heapSnapshotObjectId;

    std::unique_ptr<DomainDispatcher::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->getHeapObjectId(in_objectId, &out_heapSnapshotObjectId);
    if (response.IsFallThrough()) {
        channel()->FallThrough(dispatchable.CallId(), v8_crdtp::SpanFrom("HeapProfiler.getHeapObjectId"), dispatchable.Serialized());
        return;
    }
      if (weak->get()) {
        std::vector<uint8_t> result;
        if (response.IsSuccess()) {
          v8_crdtp::cbor::EnvelopeEncoder envelope_encoder;
          envelope_encoder.EncodeStart(&result);
          result.push_back(v8_crdtp::cbor::EncodeIndefiniteLengthMapStart());
            v8_crdtp::SerializeField(v8_crdtp::SpanFrom("heapSnapshotObjectId"), out_heapSnapshotObjectId, &result);
          result.push_back(v8_crdtp::cbor::EncodeStop());
          envelope_encoder.EncodeStop(&result);
        }
        weak->get()->sendResponse(dispatchable.CallId(), response, v8_crdtp::Serializable::From(std::move(result)));
      }
    return;
}

void DomainDispatcherImpl::getObjectByHeapObjectId(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors)
{
    // Prepare input parameters.
    protocol::Value* objectIdValue = params ? params->get("objectId") : nullptr;
    errors->SetName("objectId");
    String in_objectId = ValueConversions<String>::fromValue(objectIdValue, errors);
    protocol::Value* objectGroupValue = params ? params->get("objectGroup") : nullptr;
    Maybe<String> in_objectGroup;
    if (objectGroupValue) {
        errors->SetName("objectGroup");
        in_objectGroup = ValueConversions<String>::fromValue(objectGroupValue, errors);
    }
    if (MaybeReportInvalidParams(dispatchable, *errors)) return;
    // Declare output parameters.
    std::unique_ptr<protocol::Runtime::RemoteObject> out_result;

    std::unique_ptr<DomainDispatcher::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->getObjectByHeapObjectId(in_objectId, std::move(in_objectGroup), &out_result);
    if (response.IsFallThrough()) {
        channel()->FallThrough(dispatchable.CallId(), v8_crdtp::SpanFrom("HeapProfiler.getObjectByHeapObjectId"), dispatchable.Serialized());
        return;
    }
      if (weak->get()) {
        std::vector<uint8_t> result;
        if (response.IsSuccess()) {
          v8_crdtp::cbor::EnvelopeEncoder envelope_encoder;
          envelope_encoder.EncodeStart(&result);
          result.push_back(v8_crdtp::cbor::EncodeIndefiniteLengthMapStart());
            v8_crdtp::SerializeField(v8_crdtp::SpanFrom("result"), out_result, &result);
          result.push_back(v8_crdtp::cbor::EncodeStop());
          envelope_encoder.EncodeStop(&result);
        }
        weak->get()->sendResponse(dispatchable.CallId(), response, v8_crdtp::Serializable::From(std::move(result)));
      }
    return;
}

void DomainDispatcherImpl::getSamplingProfile(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors)
{
    // Declare output parameters.
    std::unique_ptr<protocol::HeapProfiler::SamplingHeapProfile> out_profile;

    std::unique_ptr<DomainDispatcher::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->getSamplingProfile(&out_profile);
    if (response.IsFallThrough()) {
        channel()->FallThrough(dispatchable.CallId(), v8_crdtp::SpanFrom("HeapProfiler.getSamplingProfile"), dispatchable.Serialized());
        return;
    }
      if (weak->get()) {
        std::vector<uint8_t> result;
        if (response.IsSuccess()) {
          v8_crdtp::cbor::EnvelopeEncoder envelope_encoder;
          envelope_encoder.EncodeStart(&result);
          result.push_back(v8_crdtp::cbor::EncodeIndefiniteLengthMapStart());
            v8_crdtp::SerializeField(v8_crdtp::SpanFrom("profile"), out_profile, &result);
          result.push_back(v8_crdtp::cbor::EncodeStop());
          envelope_encoder.EncodeStop(&result);
        }
        weak->get()->sendResponse(dispatchable.CallId(), response, v8_crdtp::Serializable::From(std::move(result)));
      }
    return;
}

void DomainDispatcherImpl::startSampling(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors)
{
    // Prepare input parameters.
    protocol::Value* samplingIntervalValue = params ? params->get("samplingInterval") : nullptr;
    Maybe<double> in_samplingInterval;
    if (samplingIntervalValue) {
        errors->SetName("samplingInterval");
        in_samplingInterval = ValueConversions<double>::fromValue(samplingIntervalValue, errors);
    }
    if (MaybeReportInvalidParams(dispatchable, *errors)) return;

    std::unique_ptr<DomainDispatcher::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->startSampling(std::move(in_samplingInterval));
    if (response.IsFallThrough()) {
        channel()->FallThrough(dispatchable.CallId(), v8_crdtp::SpanFrom("HeapProfiler.startSampling"), dispatchable.Serialized());
        return;
    }
    if (weak->get())
        weak->get()->sendResponse(dispatchable.CallId(), response);
    return;
}

void DomainDispatcherImpl::startTrackingHeapObjects(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors)
{
    // Prepare input parameters.
    protocol::Value* trackAllocationsValue = params ? params->get("trackAllocations") : nullptr;
    Maybe<bool> in_trackAllocations;
    if (trackAllocationsValue) {
        errors->SetName("trackAllocations");
        in_trackAllocations = ValueConversions<bool>::fromValue(trackAllocationsValue, errors);
    }
    if (MaybeReportInvalidParams(dispatchable, *errors)) return;

    std::unique_ptr<DomainDispatcher::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->startTrackingHeapObjects(std::move(in_trackAllocations));
    if (response.IsFallThrough()) {
        channel()->FallThrough(dispatchable.CallId(), v8_crdtp::SpanFrom("HeapProfiler.startTrackingHeapObjects"), dispatchable.Serialized());
        return;
    }
    if (weak->get())
        weak->get()->sendResponse(dispatchable.CallId(), response);
    return;
}

void DomainDispatcherImpl::stopSampling(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors)
{
    // Declare output parameters.
    std::unique_ptr<protocol::HeapProfiler::SamplingHeapProfile> out_profile;

    std::unique_ptr<DomainDispatcher::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->stopSampling(&out_profile);
    if (response.IsFallThrough()) {
        channel()->FallThrough(dispatchable.CallId(), v8_crdtp::SpanFrom("HeapProfiler.stopSampling"), dispatchable.Serialized());
        return;
    }
      if (weak->get()) {
        std::vector<uint8_t> result;
        if (response.IsSuccess()) {
          v8_crdtp::cbor::EnvelopeEncoder envelope_encoder;
          envelope_encoder.EncodeStart(&result);
          result.push_back(v8_crdtp::cbor::EncodeIndefiniteLengthMapStart());
            v8_crdtp::SerializeField(v8_crdtp::SpanFrom("profile"), out_profile, &result);
          result.push_back(v8_crdtp::cbor::EncodeStop());
          envelope_encoder.EncodeStop(&result);
        }
        weak->get()->sendResponse(dispatchable.CallId(), response, v8_crdtp::Serializable::From(std::move(result)));
      }
    return;
}

void DomainDispatcherImpl::stopTrackingHeapObjects(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors)
{
    // Prepare input parameters.
    protocol::Value* reportProgressValue = params ? params->get("reportProgress") : nullptr;
    Maybe<bool> in_reportProgress;
    if (reportProgressValue) {
        errors->SetName("reportProgress");
        in_reportProgress = ValueConversions<bool>::fromValue(reportProgressValue, errors);
    }
    protocol::Value* treatGlobalObjectsAsRootsValue = params ? params->get("treatGlobalObjectsAsRoots") : nullptr;
    Maybe<bool> in_treatGlobalObjectsAsRoots;
    if (treatGlobalObjectsAsRootsValue) {
        errors->SetName("treatGlobalObjectsAsRoots");
        in_treatGlobalObjectsAsRoots = ValueConversions<bool>::fromValue(treatGlobalObjectsAsRootsValue, errors);
    }
    if (MaybeReportInvalidParams(dispatchable, *errors)) return;

    std::unique_ptr<DomainDispatcher::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->stopTrackingHeapObjects(std::move(in_reportProgress), std::move(in_treatGlobalObjectsAsRoots));
    if (response.IsFallThrough()) {
        channel()->FallThrough(dispatchable.CallId(), v8_crdtp::SpanFrom("HeapProfiler.stopTrackingHeapObjects"), dispatchable.Serialized());
        return;
    }
    if (weak->get())
        weak->get()->sendResponse(dispatchable.CallId(), response);
    return;
}

void DomainDispatcherImpl::takeHeapSnapshot(const v8_crdtp::Dispatchable& dispatchable, DictionaryValue* params, ErrorSupport* errors)
{
    // Prepare input parameters.
    protocol::Value* reportProgressValue = params ? params->get("reportProgress") : nullptr;
    Maybe<bool> in_reportProgress;
    if (reportProgressValue) {
        errors->SetName("reportProgress");
        in_reportProgress = ValueConversions<bool>::fromValue(reportProgressValue, errors);
    }
    protocol::Value* treatGlobalObjectsAsRootsValue = params ? params->get("treatGlobalObjectsAsRoots") : nullptr;
    Maybe<bool> in_treatGlobalObjectsAsRoots;
    if (treatGlobalObjectsAsRootsValue) {
        errors->SetName("treatGlobalObjectsAsRoots");
        in_treatGlobalObjectsAsRoots = ValueConversions<bool>::fromValue(treatGlobalObjectsAsRootsValue, errors);
    }
    if (MaybeReportInvalidParams(dispatchable, *errors)) return;

    std::unique_ptr<DomainDispatcher::WeakPtr> weak = weakPtr();
    DispatchResponse response = m_backend->takeHeapSnapshot(std::move(in_reportProgress), std::move(in_treatGlobalObjectsAsRoots));
    if (response.IsFallThrough()) {
        channel()->FallThrough(dispatchable.CallId(), v8_crdtp::SpanFrom("HeapProfiler.takeHeapSnapshot"), dispatchable.Serialized());
        return;
    }
    if (weak->get())
        weak->get()->sendResponse(dispatchable.CallId(), response);
    return;
}

namespace {
// This helper method (with a static map of redirects) is used from Dispatcher::wire
// immediately below.
const std::vector<std::pair<v8_crdtp::span<uint8_t>, v8_crdtp::span<uint8_t>>>& SortedRedirects() {
  static auto* redirects = [](){
    auto* redirects = new std::vector<std::pair<v8_crdtp::span<uint8_t>, v8_crdtp::span<uint8_t>>>{
    };
    return redirects;
  }();
  return *redirects;
}
}  // namespace

// static
void Dispatcher::wire(UberDispatcher* uber, Backend* backend)
{
    auto dispatcher = std::make_unique<DomainDispatcherImpl>(uber->channel(), backend);
    uber->WireBackend(v8_crdtp::SpanFrom("HeapProfiler"), SortedRedirects(), std::move(dispatcher));
}

} // HeapProfiler
} // namespace v8_inspector
} // namespace protocol
