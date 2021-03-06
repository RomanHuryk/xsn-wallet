#include "WalletAssetViewModel.hpp"
#include "Models/WalletTransactionsListModel.hpp"
#include "Models/WalletDataSource.hpp"
#include "ViewModels/ApplicationViewModel.hpp"

//==============================================================================

WalletAssetViewModel::WalletAssetViewModel(QObject *parent)
{
}

//==============================================================================

WalletAssetViewModel::~WalletAssetViewModel()
{

}

//==============================================================================

QObject *WalletAssetViewModel::transactionsListModel() const
{
    return _walletTransactionsListModel.get();
}

//==============================================================================

QString WalletAssetViewModel::balance() const
{
    return QString("150 + 150 = 300");
}

//==============================================================================

void WalletAssetViewModel::setApplicationViewModel(ApplicationViewModel *applicationViewModel)
{
    _walletDataSource = applicationViewModel->dataSource();
    init();

    emit applicationViewModelChanged();
}

//==============================================================================

void WalletAssetViewModel::init()
{
    initTransactionsListModel();
}

//==============================================================================

void WalletAssetViewModel::initTransactionsListModel()
{
    _walletTransactionsListModel.reset(new WalletTransactionsListModel(_walletDataSource, "Bitcoin"));
}

//==============================================================================
