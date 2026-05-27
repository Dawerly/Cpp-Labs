#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Parcel;
class ParcelState;

class ParcelState {
protected:
    Parcel* parcel;
public:
    ParcelState(Parcel* parcel_) : parcel(parcel_) {}
    virtual ~ParcelState() = default;

    virtual void AcceptedInPost() { OperationIsNotAllowed("AcceptedInPost"); }
    virtual void LeftPost() { OperationIsNotAllowed("LeftPost"); }
    virtual void Shipping() { OperationIsNotAllowed("Shipping"); }
    virtual void ArrivedPost() { OperationIsNotAllowed("ArrivedPost"); }
    virtual void Waiting() { OperationIsNotAllowed("Waiting"); }
    virtual void Paid() { OperationIsNotAllowed("Paid"); }
    virtual void Received() { OperationIsNotAllowed("Received"); }
    virtual void Cancel() { OperationIsNotAllowed("Cancel"); }

    virtual const char* GetStateName() const { return "Unknown"; }

private:
    void OperationIsNotAllowed(const string& operationName) {
        cout << "Operation " << operationName 
             << " is not allowed for Parcel's state " 
             << GetStateName() << endl;
    }
};

class Parcel {
private:
    int price;
    string SendAddress;
    string ReceiveAddress;
    string parcelname;
    ParcelState* current_state;

public:
    Parcel(int price_, const string& SendAddress_, const string& ReceiveAddress_, const string& parcelname_);
    ~Parcel();

    void SetParcelState(ParcelState* state_);
    void WriteCurrentStateName();

    void AcceptedInPost() { current_state->AcceptedInPost(); }
    void LeftPost()       { current_state->LeftPost(); }
    void Shipping()       { current_state->Shipping(); }
    void ArrivedPost()    { current_state->ArrivedPost(); }
    void Waiting()        { current_state->Waiting(); }
    void Paid()           { current_state->Paid(); }
    void Received()       { current_state->Received(); }
    void Cancel()         { current_state->Cancel(); }

    void DoAcceptedInPost() { cout << "-> Parcel accepted in post office." << endl; }
    void DoLeftPost()       { cout << "-> Parcel left post office." << endl; }
    void DoShipping()       { cout << "-> Parcel is shipping." << endl; }
    void DoArrivedPost()    { cout << "-> Parcel arrived in post office." << endl; }
    void DoWaiting()        { cout << "-> Parcel is waiting for payment." << endl; }
    void DoPaid()           { cout << "-> Parcel is paid." << endl; }    
    void DoReceived()       { cout << "-> Parcel is received." << endl; }
    void DoCancel()         { cout << "-> Parcel is cancelled." << endl; }
};

class Accepted : public ParcelState {
public:
    Accepted(Parcel* parcel_) : ParcelState(parcel_) {}
    void LeftPost() override;
    void Cancel() override;
protected:
    const char* GetStateName() const override { return "Accepted"; }
};

class Left : public ParcelState {
public: 
    Left(Parcel* parcel_) : ParcelState(parcel_) {}
    void Shipping() override;
    void Cancel() override;
protected:
    const char* GetStateName() const override { return "Left"; }
};

class ShippingState : public ParcelState {
public: 
    ShippingState(Parcel* parcel_) : ParcelState(parcel_) {}
    void ArrivedPost() override;
    void Cancel() override;
protected:
    const char* GetStateName() const override { return "Shipping"; }
};

class Arrived : public ParcelState {
public: 
    Arrived(Parcel* parcel_) : ParcelState(parcel_) {}
    void Waiting() override;
    void Cancel() override;
protected:
    const char* GetStateName() const override { return "Arrived"; }
};

class WaitingState : public ParcelState {
public: 
    WaitingState(Parcel* parcel_) : ParcelState(parcel_) {}
    void Paid() override;
    void Cancel() override;
protected:
    const char* GetStateName() const override { return "Waiting"; }
};

class PaidState : public ParcelState {
public: 
    PaidState(Parcel* parcel_) : ParcelState(parcel_) {}
    void Received() override;
    void Cancel() override; 
protected:
    const char* GetStateName() const override { return "Paid"; }
};

class ReceivedState : public ParcelState {
public: 
    ReceivedState(Parcel* parcel_) : ParcelState(parcel_) {}
protected:
    const char* GetStateName() const override { return "Received"; }
};

class Cancelled : public ParcelState {
public: 
    Cancelled(Parcel* parcel_) : ParcelState(parcel_) {}
protected:
    const char* GetStateName() const override { return "Cancelled"; }
};

Parcel::Parcel(int price_, const string& SendAddress_, const string& ReceiveAddress_, const string& parcelname_)
    : price(price_), SendAddress(SendAddress_), ReceiveAddress(ReceiveAddress_), parcelname(parcelname_) {
    current_state = new Accepted(this);
}

Parcel::~Parcel() {
    delete current_state;
}

void Parcel::SetParcelState(ParcelState* state_) {
    delete current_state;
    current_state = state_;
}

void Parcel::WriteCurrentStateName() {
    cout << "Current Parcel's state: " << current_state->GetStateName() << endl;
}

void Accepted::LeftPost() {
    parcel->DoLeftPost();
    parcel->SetParcelState(new Left(parcel));
}
void Accepted::Cancel() {
    parcel->DoCancel();
    parcel->SetParcelState(new Cancelled(parcel));
}

void Left::Shipping() {
    parcel->DoShipping();
    parcel->SetParcelState(new ShippingState(parcel));
}
void Left::Cancel() {
    parcel->DoCancel();
    parcel->SetParcelState(new Cancelled(parcel));
}

void ShippingState::ArrivedPost() {
    parcel->DoArrivedPost();
    parcel->SetParcelState(new Arrived(parcel));
}
void ShippingState::Cancel() {
    parcel->DoCancel();
    parcel->SetParcelState(new Cancelled(parcel));
}

void Arrived::Waiting() {
    parcel->DoWaiting();
    parcel->SetParcelState(new WaitingState(parcel));
}
void Arrived::Cancel() {
    parcel->DoCancel();
    parcel->SetParcelState(new Cancelled(parcel));
}

void WaitingState::Paid() {
    parcel->DoPaid();
    parcel->SetParcelState(new PaidState(parcel));
}
void WaitingState::Cancel() {
    parcel->DoCancel();
    parcel->SetParcelState(new Cancelled(parcel));
}

void PaidState::Received() {
    parcel->DoReceived();
    parcel->SetParcelState(new ReceivedState(parcel));
}
void PaidState::Cancel() {
    parcel->DoCancel();
    parcel->SetParcelState(new Cancelled(parcel));
}

void StartProgram() {
    Parcel parcel(1000, "Kyiv", "Lviv", "Books");
    parcel.WriteCurrentStateName();
    cout << "-----------------------------------" << endl;

    parcel.LeftPost();
    parcel.WriteCurrentStateName();
    cout << "-----------------------------------" << endl;

    parcel.Shipping();
    parcel.WriteCurrentStateName();
    cout << "-----------------------------------" << endl;

    parcel.ArrivedPost();
    parcel.WriteCurrentStateName();
    cout << "-----------------------------------" << endl;

    parcel.Waiting();
    parcel.WriteCurrentStateName();
    cout << "-----------------------------------" << endl;

    parcel.Paid();
    parcel.WriteCurrentStateName();
    cout << "-----------------------------------" << endl;

    parcel.Received();
    parcel.WriteCurrentStateName();
    cout << "-----------------------------------" << endl;

    parcel.Cancel(); 
}

int main() {
    StartProgram();
    return 0;
}